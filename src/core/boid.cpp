#include "boid.h"

#include <cmath>
#include <cstdlib>

#include <GL/gl.h>

float u()
{
	return ((float) rand() / RAND_MAX);
}

float r()
{
	return 1.8 * u() - 0.9;
}

namespace BoidBox
{
	Boid::Boid()
	{
		position = QVector3D(r(), r(), r());
		heading  = QVector3D(r(), r() / 2, r());
		heading.normalize();
		speed = u();
	}
	
	void Boid::draw()
	{
		float alt = asin(heading.y());
		float azm = atan2(heading.x(), heading.z());
		
		glPushMatrix();
		{
			glTranslatef(position.x(), position.y(), position.z());
			glRotatef(+azm * 180/M_PI, 0, 1, 0);
			glRotatef(-alt * 180/M_PI, 1, 0, 0);
			
			glBegin(GL_QUADS);
			{
				glColor3f(0.6, 0.6, 0.6);
				glNormal3f(0, 1, 0);
				
				// Left Wing
				glVertex3f(-0.005,  0.000,  0.000);
				glVertex3f(-0.001,  0.000,  0.000);
				glVertex3f(-0.001,  0.000, +0.009);
				glVertex3f(-0.005,  0.000, +0.003);
				
				// Right Wing
				glVertex3f(+0.005,  0.000,  0.000);
				glVertex3f(+0.001,  0.000,  0.000);
				glVertex3f(+0.001,  0.000, +0.009);
				glVertex3f(+0.005,  0.000, +0.003);
				
				glColor3f(speed, 0, 1 - speed);
				glNormal3f(1.0/sqrt(2), 1.0/sqrt(2), 0);
				
				// Left Wingtip
				glVertex3f(+0.006, +0.001,  0.000);
				glVertex3f(+0.005,  0.000,  0.000);
				glVertex3f(+0.005,  0.000, +0.003);
				glVertex3f(+0.006, +0.001, +0.001);
				
				// Left Fuselage
				glVertex3f(+0.001, -0.000,  0.000);
				glVertex3f( 0.000, -0.001,  0.000);
				glVertex3f( 0.000, -0.001, +0.011);
				glVertex3f(+0.001, -0.000, +0.009);
				
				glNormal3f(-1.0/sqrt(2), 1.0/sqrt(2), 0);
				
				// Right Wingtip
				glVertex3f(-0.006, +0.001,  0.000);
				glVertex3f(-0.005,  0.000,  0.000);
				glVertex3f(-0.005,  0.000, +0.003);
				glVertex3f(-0.006, +0.001, +0.001);
				
				// Right Fuselage
				glVertex3f(-0.001,  0.000,  0.000);
				glVertex3f( 0.000, -0.001,  0.000);
				glVertex3f( 0.000, -0.001, +0.011);
				glVertex3f(-0.001,  0.000, +0.009);
			}
			glEnd();
		}
		glPopMatrix();
	}
	
	void Boid::move(float minspd, float varspd)
	{
		float dx = pow(position.x(), 7) / (position.x() * position.x() - 1);
		float dy = pow(position.y(), 7) / (position.y() * position.y() - 1);
		float dz = pow(position.z(), 7) / (position.z() * position.z() - 1);
		target += QVector3D(dx, dy / 2, dz);
		target.normalize();

		heading   = target;
		position += (varspd * speed + minspd) * heading;
	}
}

