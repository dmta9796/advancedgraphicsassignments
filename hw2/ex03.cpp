//
//  Ex03:  Procedural Textures
//  Willem A. (Vlakkies) Schreuder
//  CSCI 4239/5239 Spring 2018
//

#include <QApplication>
#include "ex03viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Ex03viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
