#  Ubuntu:  apt-get install qtmultimedia5-dev libqt5multimedia5-plugins
win32:LIBS += -lopengl32
HEADERS = ex12viewer.h ex12opengl.h ex12frame.h CUgl.h Object.h Type.h
SOURCES = ex12.cpp ex12viewer.cpp ex12opengl.cpp ex12frame.cpp CUgl.cpp
QT += opengl multimedia
RESOURCES = ex12.qrc
