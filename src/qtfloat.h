#ifndef BOIDBOX_QTFLOAT_H
#define BOIDBOX_QTFLOAT_H

#include <QtCore/QObject>
#include <QtCore/QString>

namespace BoidBox
{
	class QtFloat : public QObject
	{ Q_OBJECT
	protected:
		float* mValue;
		
	public:
		QtFloat(float* value)
		{
			mValue = value;
		}
		
		float getValue() const
		{
			return *mValue;
		}
		
	public slots:
		void setValue(float value)
		{
			if(*mValue != value)
			{
				*mValue = value;
				emit valueChanged(value);
				emit valueChanged(double(value));
			}
		}
		
		void setValue(double value)
		{
			setValue(float(value));
		}
		
	signals:
		void valueChanged(float);
		void valueChanged(double);
	
	public:
		operator float () const
		{
			return *mValue;
		}
		
		operator QString () const
		{
			return QString::number(*mValue, 'g', 2);
		}
		
		QtFloat& operator = (float value)
		{
			setValue(value);
			return *this;
		}
	};
}

#endif

