//
//  HW1:  position to RGB shader
//  adapted from Basic Shader
//

#include <QApplication>
#include "ex01viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Ex01viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
