CXXFLAGS = --std=c++11 -I/usr/include/qt5 -fPIC -O3 -march=native
LIBS = -lQt5Core -lQt5Widgets -lQt5Gui -lQt5OpenGL -lGL

boidbox :\
		src/main.o\
		src/float-slider.o\
		src/moc_float-slider.o\
		src/demo-widget.o\
		src/display-widget.o\
		src/moc_display-widget.o\
		src/control-widget.o\
		src/moc_control-widget.o\
		src/moc_qtfloat.o\
		src/boid.o\
		src/box.o
	${CXX} $(CXXFLAGS) -o $@ $+ $(LIBS)
src/moc_%.cpp : src/%.h
	moc -o $@ $+
clean :
	rm -rf boidbox src/*.o
