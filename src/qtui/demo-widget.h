#ifndef BOIDBOX_DEMOWIDGET_H
#define BOIDBOX_DEMOWIDGET_H

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

namespace BoidBox
{
	class Box;
	class ControlWidget;
	class DisplayWidget;
	
	class DemoWidget : public QWidget
	{
	protected:
		QHBoxLayout*   mLayout;
		DisplayWidget* mDisplay;
		ControlWidget* mControl;
		
	public:
		DemoWidget(Box* box, QWidget* parent = 0);
		
		void animate();
	};
}

#endif

