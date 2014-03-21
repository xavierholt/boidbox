#include "display-widget.h"

#include "../core/box.h"

#include <QtGui/QMouseEvent>
#include <QtGui/QWheelEvent>

namespace BoidBox
{
	DisplayWidget::DisplayWidget(Box* box, QWidget* parent): QGLWidget(parent)
	{
		mBox = box;
		
		mAltitude = 45.0;
		mAzimuth  = 45.0;
		mDistance =  2.0;
		
		mTimer.setInterval(40);
		mTimer.setSingleShot(false);
		connect(&mTimer, SIGNAL(timeout()), this, SLOT(move()));
	}
	
	void DisplayWidget::animate()
	{
		mTimer.start();
	}
	
	void DisplayWidget::initializeGL()
	{
		glClearColor(255, 255, 255, 0);

		glEnable(GL_DEPTH_TEST);
	//	glEnable(GL_CULL_FACE);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	//	glEnable(GL_MULTISAMPLE);
		static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	}
	
	void DisplayWidget::mouseMoveEvent(QMouseEvent* e)
	{
		mAltitude += (e->y() - mMouseY);
		mAzimuth  += (e->x() - mMouseX);
		mousePressEvent(e);
		updateGL();
	}
	
	void DisplayWidget::mousePressEvent(QMouseEvent* e)
	{
		mMouseX = e->x();
		mMouseY = e->y();
	}
	
	void DisplayWidget::move()
	{
		mBox->calc();
		mBox->move();
		updateGL();
	}
	
	void DisplayWidget::paintGL()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef(0.0, 0.0, -mDistance);
		glRotatef(mAltitude, 1.0, 0.0, 0.0);
		glRotatef(mAzimuth,  0.0, 1.0, 0.0);
		
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);
		{
			glColor3f(0.9, 0.7, 0.7);
			glVertex3f(+1, 0, 0);
			glVertex3f(-1, 0, 0);
			
			glColor3f(0.7, 0.9, 0.7);
			glVertex3f(0, +1, 0);
			glVertex3f(0, -1, 0);
			
			glColor3f(0.7, 0.7, 0.9);
			glVertex3f(0, 0, +1);
			glVertex3f(0, 0, -1);
		}
		glEnd();
		
		glEnable(GL_LIGHTING);
		mBox->draw();
	}
	
	void DisplayWidget::resizeGL(int w, int h)
	{
		glViewport(0, 0, w, h);
		
		float r = (float) w / (float) h;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		
		float v = 0.1;
		glFrustum(-r*v, +r*v, -v, +v, v, 7);
		glMatrixMode(GL_MODELVIEW);
	}
	
	void DisplayWidget::wheelEvent(QWheelEvent* e)
	{
		QPoint point = e->angleDelta();
		mDistance *= (point.y() > 0)? 0.9 : 1.1;
	}
}

