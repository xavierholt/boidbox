#include "demo-widget.h"
#include "control-widget.h"
#include "display-widget.h"

namespace BoidBox
{
	DemoWidget::DemoWidget(Box* box, QWidget* parent): QWidget(parent)
	{
		mDisplay = new DisplayWidget(box);
		mControl = new ControlWidget(box);
		
		mLayout  = new QHBoxLayout();
		mLayout->addWidget(mDisplay, 1);
		mLayout->addWidget(mControl, 0);
		mLayout->setContentsMargins(0, 0, 0, 0);
		setLayout(mLayout);
	}
	
	void DemoWidget::animate()
	{
		mDisplay->animate();
	}
}

