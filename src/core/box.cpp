#include "box.h"
#include "boid.h"

#include <cmath>

namespace BoidBox
{
	Box::Box(int nboids)
	{
		mNBoids = nboids;
		mBoids = new Boid[nboids];
		
		mCohesionWeight   = 0.1;
		mCohesionFalloff  = 30;
		mAvoidanceWeight  = 1.0;
		mAvoidanceFalloff = 40;
		mAlignmentWeight  = 0.2;
		mAlignmentFalloff = 40;
		mMinimumSpeed     = 0.005;
		mVariableSpeed    = 0.003;
	}
	
	Box::~Box()
	{
		delete [] mBoids;
	}
	
	void Box::calc()
	{
		for(int i = 1; i < mNBoids; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				Boid& a = mBoids[i];
				Boid& b = mBoids[j];
				
				QVector3D diff = a.position - b.position;
				float dist = diff.length();
				diff.normalize();
				
				// Alignment
				float pull = mAlignmentWeight * exp(-mAlignmentFalloff * dist);
				a.target += pull * b.heading;
				b.target += pull * a.heading;
	
				// Cohesion / Separation
				pull  = mCohesionWeight  * exp(-mCohesionFalloff  * dist);
				pull -= mAvoidanceWeight * exp(-mAvoidanceFalloff * dist);
				a.target -= pull * diff;
				b.target += pull * diff;
			}
		}
	}
	
	void Box::draw()
	{
		for(int i = 0; i < mNBoids; ++i)
		{
			mBoids[i].draw();
		}
	}
	
	void Box::move()
	{
		for(int i = 0; i < mNBoids; ++i)
		{
			mBoids[i].move(mMinimumSpeed, mVariableSpeed);
		}
	}
}
