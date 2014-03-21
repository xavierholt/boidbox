#ifndef BOIDBOX_WIDGET_H
#define BOIDBOX_WIDGET_H

#include <QtCore/QTimer>
#include <QtOpenGL/QGLWidget>

namespace BoidBox
{
	class Box;
	
	class DisplayWidget : public QGLWidget
	{ Q_OBJECT
	protected:
		Box*   mBox;
		int    mMouseX;
		int    mMouseY;
		float  mAltitude;
		float  mAzimuth;
		float  mDistance;
		QTimer mTimer;
		
	protected:
		void initializeGL();
		void mouseMoveEvent(QMouseEvent* e);
		void mousePressEvent(QMouseEvent* e);
		void paintGL();
		void resizeGL(int w, int h);
		void wheelEvent(QWheelEvent* e);
		
	public:
		DisplayWidget(Box* box, QWidget* parent = 0);
		
		void animate();
		
	public slots:
		void move();
	};
}

#endif

