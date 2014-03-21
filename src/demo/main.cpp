#include "../core/box.h"
#include "../qtui/demo-widget.h"

#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	BoidBox::Box box(400);
	BoidBox::DemoWidget widget(&box);
	widget.showMaximized();
	widget.animate();
	return app.exec();
}

