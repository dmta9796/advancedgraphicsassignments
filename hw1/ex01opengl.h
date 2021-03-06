//
//  OpenGL Ex01opengl Widget
//

#ifndef EX01OPENGL_H
#define EX01OPENGL_H

#include <QtOpenGL>
#include <QString>
#include <QVector>
#include <QTimer>
#include <QElapsedTimer>
#include "Object.h"

class Ex01opengl : public QOpenGLWidget
{
Q_OBJECT
private:
   bool    light;     //  Lighting
   int     mode;      //  Display mode
   int     th,ph;     //  Display angles
   bool    mouse;     //  Mouse pressed
   QPoint  pos;       //  Mouse position
   int     fov;       //  Field of view
   double  dim;       //  Display size
   double  asp;       //  Sceen aspect ratio
   double xpos;      //x position of object
   double ypos;      //y position of object
   double zpos;      //z position of object
   double wpos;      //w position of object
   
   Object* obj;       //  Object
   QTimer           timer;       //  Timer for animations
   QElapsedTimer    time;        //  Track elapsed time
   QOpenGLShaderProgram shader;  //  Shader
   QVector<Object*> objects;     //  Objects
public:
   Ex01opengl(QWidget* parent=0);                  //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
public slots:
    void setShader(int on);                //  Slot to set shader
    void setPerspective(int on);           //  Slot to set projection type
    void setObject(int type);              //  Slot to set displayed object
    void setLighting(int on);              //  Slot to set lighting
    void setXPos(int xpos);                //  Slot to set xpos
    void setYPos(int ypos);                //  Slot to set ypos
    void setZPos(int zpos);                //  Slot to set zpos
    void setWPos(int wpos);                //  Slot to set wpos
signals:
    void angles(QString text);             //  Signal for view angles
protected:
    void initializeGL();                   //  Initialize widget
    void resizeGL(int width, int height);  //  Resize widget
    void paintGL();                        //  Draw widget
    void mousePressEvent(QMouseEvent*);    //  Mouse pressed
    void mouseReleaseEvent(QMouseEvent*);  //  Mouse released
    void mouseMoveEvent(QMouseEvent*);     //  Mouse moved
    void wheelEvent(QWheelEvent*);         //  Mouse wheel
private:
   void Fatal(QString message);            //  Error handler
   void Projection();                      //  Update projection
};

#endif
