#ifndef BOIDBOX_BOX_H
#define BOIDBOX_BOX_H

#include "boid.h"

#include <functional>

namespace BoidBox
{
	class Box
	{
	protected:
		int   mNBoids;
		Boid* mBoids;
		
	public:
		float mCohesionWeight;
		float mCohesionFalloff;
		float mAvoidanceWeight;
		float mAvoidanceFalloff;
		float mAlignmentWeight;
		float mAlignmentFalloff;
		float mMinimumSpeed;
		float mVariableSpeed;
		
	public:
		Box(int nboids);
		~Box();
		
		void calc();
		void draw();
		void each(std::function<void(const Boid&)> callback) const;
		void move();
	};
}

#endif

