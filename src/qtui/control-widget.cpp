#include "control-widget.h"

#include "../core/box.h"

namespace BoidBox
{
	ControlWidget::Single::Single(float* value, float min, float max, float step): QDoubleSpinBox()
	{
		mBinding = new QtFloat(value);
		setDecimals(4);
		setValue(*mBinding);
		setSingleStep(step);
		setMinimum(min);
		setMaximum(max);
		
		connect(this,     SIGNAL(valueChanged(double)), mBinding, SLOT(setValue(double)));
		connect(mBinding, SIGNAL(valueChanged(double)), this,     SLOT(setValue(double)));
	}
	
	ControlWidget::Single::~Single()
	{
		// Nothing to do?
	}
	
	ControlWidget::ControlWidget(Box* box, QWidget* parent): QWidget(parent)
	{
		mBox = box;
		mLayout = new QFormLayout();
		mLayout->addRow("Alignment Weight",  new Single(&mBox->mAlignmentWeight,  0, 2, 0.01));
		mLayout->addRow("Alignment Falloff", new Single(&mBox->mAlignmentFalloff, 0, 50));
		mLayout->addRow("Cohesion Weight",   new Single(&mBox->mCohesionWeight,   0, 2, 0.01));
		mLayout->addRow("Cohesion Falloff",  new Single(&mBox->mCohesionFalloff,  0, 50));
		mLayout->addRow("Avoidance Weight",  new Single(&mBox->mAvoidanceWeight,  0, 2, 0.01));
		mLayout->addRow("Avoidance Falloff", new Single(&mBox->mAvoidanceFalloff, 0, 50));
		mLayout->addRow("Minimum Speed",     new Single(&mBox->mMinimumSpeed,     0, 0.02, 0.001));
		mLayout->addRow("Variable Speed",    new Single(&mBox->mVariableSpeed,    0, 0.02, 0.001));
		//mLayout->addStretch();
		setLayout(mLayout);
	}
}

