#ifndef BOIDBOX_CONTROL_WIDGET_H
#define BOIDBOX_CONTROL_WIDGET_H

#include "box.h"
#include "qtfloat.h"

#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QWidget>

namespace BoidBox
{
	class ControlWidget : public QWidget
	{
		class Single : public QDoubleSpinBox
		{
		protected:
			QtFloat* mBinding;
			
		public:
			Single(float* value, float min, float max, float step = 1);
			~Single();
		};
		
	protected:
		Box*         mBox;
		QFormLayout* mLayout;
		
	public:
		ControlWidget(Box* box, QWidget* parent = 0);
	};
}

#endif

