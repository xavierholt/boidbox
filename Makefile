CXXFLAGS = --std=c++11 -I/usr/include/qt5 -fPIC -O3 -march=native
LIBS = -lQt5Core -lQt5Widgets -lQt5Gui -lQt5OpenGL -lGL

boidbox :\
		src/core/boid.o\
		src/core/box.o\
		src/qtui/demo-widget.o\
		src/qtui/control-widget.o\
		src/qtui/display-widget.o\
		src/qtui/moc_display-widget.o\
		src/qtui/moc_qtfloat.o\
		src/demo/main.o
	${CXX} $(CXXFLAGS) -o $@ $+ $(LIBS)
src/moc_%.cpp : src/%.h
	moc -o $@ $+
clean :
	rm -rf boidbox src/*.o
