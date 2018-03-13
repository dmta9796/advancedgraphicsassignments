//
//  Ex01viewer Widget
//

#include <QComboBox>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include "ex01viewer.h"
#include "ex01opengl.h"

//
//  Constructor
//
Ex01viewer::Ex01viewer()
{
   //  Set window title
   setWindowTitle(tr("HW1: Dmitriy Tarasov"));

   //  Create new OpenGL widget
   Ex01opengl* ogl = new Ex01opengl;

   //  Select shader
   QComboBox* shader = new QComboBox();
   shader->addItem("None");
   shader->addItem("Basic");

   //  Select projection
   QComboBox* projection = new QComboBox();
   projection->addItem("Orthogonal");
   projection->addItem("Perspective");

   //  Select object
   QComboBox* object = new QComboBox();
   object->addItem("Cube");
   object->addItem("Teapot");
   object->addItem("Rocket");
   object->addItem("Suzanne");

   //  Lighting
   QCheckBox* lighting = new QCheckBox("");

   //Positions
   QSlider* xpos=new QSlider(Qt::Horizontal,0);
   xpos->setRange(-128, 128);
   xpos->setValue(0);
   
   QSlider* ypos=new QSlider(Qt::Horizontal,0);
   ypos->setRange(-128, 128);
   ypos->setValue(0);
   
   QSlider* zpos=new QSlider(Qt::Horizontal,0);
   zpos->setRange(-128, 128);
   zpos->setValue(0);
   
   QSlider* wpos=new QSlider(Qt::Horizontal,0);
   wpos->setRange(1, 256);
   wpos->setValue(128);
   
   //  View angle
   QLabel* angles = new QLabel();

   //  Quit
   QPushButton* quit = new QPushButton("Quit");

   //  Set layout of child widgets
   QGridLayout* layout = new QGridLayout;
   layout->addWidget(ogl,0,0,10,1);
   layout->addWidget(new QLabel("Shader"),0,1);
   layout->addWidget(shader,0,2);
   layout->addWidget(new QLabel("Projection"),1,1);
   layout->addWidget(projection,1,2);
   layout->addWidget(new QLabel("Object"),2,1);
   layout->addWidget(object,2,2);
   layout->addWidget(new QLabel("Lighting"),3,1);
   layout->addWidget(lighting,3,2);
   layout->addWidget(new QLabel("Angles"),4,1);
   layout->addWidget(angles,4,2);
   layout->addWidget(new QLabel("xpos"),5,1);
   layout->addWidget(xpos,5,2);
   layout->addWidget(new QLabel("ypos"),6,1);
   layout->addWidget(ypos,6,2);
   layout->addWidget(new QLabel("zpos"),7,1);
   layout->addWidget(zpos,7,2);
   layout->addWidget(new QLabel("wpos"),8,1);
   layout->addWidget(wpos,8,2);
   layout->addWidget(quit,9,2);

   //  Manage resizing
   layout->setColumnStretch(0,100);
   layout->setColumnMinimumWidth(0,100);
   layout->setRowStretch(5,100);
   setLayout(layout);

   //  Connect valueChanged() signals to ogl
   connect(shader,SIGNAL(currentIndexChanged(int))     , ogl,SLOT(setShader(int)));
   connect(object,SIGNAL(currentIndexChanged(int))     , ogl,SLOT(setObject(int)));
   connect(projection,SIGNAL(currentIndexChanged(int)) , ogl,SLOT(setPerspective(int)));
   connect(lighting,SIGNAL(stateChanged(int))          , ogl,SLOT(setLighting(int)));
   connect(xpos,SIGNAL(valueChanged(int))              , ogl,SLOT(setXPos(int)));
   connect(ypos,SIGNAL(valueChanged(int))              , ogl,SLOT(setYPos(int)));
   connect(zpos,SIGNAL(valueChanged(int))              , ogl,SLOT(setZPos(int)));
   connect(wpos,SIGNAL(valueChanged(int))              , ogl,SLOT(setWPos(int)));

   //  Connect angles() signal to label
   connect(ogl,SIGNAL(angles(QString)) , angles,SLOT(setText(QString)));
   //  Connect quit() signal to qApp::quit()
   connect(quit,SIGNAL(pressed()) , qApp,SLOT(quit()));
}
