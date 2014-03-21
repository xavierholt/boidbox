#ifndef BOIDBOX_BOID_H
#define BOIDBOX_BOID_H

#include <QtGui/QVector3D>

namespace BoidBox
{
	class Boid
	{
	public:
		QVector3D position;
		QVector3D heading;
		QVector3D target;
		float     speed;
		
	public:
		Boid();
		
		void draw();
		void move(float minspd, float varspd);
	};
}

#endif

