//
//  Rocket class
//
#include "Rocket.h"

//
//  Constructor
//
Rocket::Rocket(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Rocket::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}
//
//compute rocket normals
//
double *normalplane(double *p1,double *p2, double *p3,double *norm)
{
	double a1[3]={0,0,0};
	double a2[3]={0,0,0};
	a1[0]=p2[0]-p1[0];
	a1[1]=p2[1]-p1[1];
	a1[2]=p2[2]-p1[2];
	a2[0]=p3[0]-p1[0];
	a2[1]=p3[1]-p1[1];
	a2[2]=p3[2]-p1[2];
	//printf("x:%.2f, y:%.2f, z:%.2f",a1[0],a1[1],a1[2]);
	norm[0]=(a1[1]*a2[2])-(a2[1]*a1[2]);
	norm[1]=-(a1[0]*a2[2])+(a2[0]*a1[2]);
	norm[2]=(a1[0]*a2[1])-(a2[0]*a1[1]);
	return norm;
}
//rocket fin
void fin()
{
	double n1[3]={0,0,0};
	double n2[3]={0,0,0};
	double n3[3]={0,0,0};
	double n4[3]={0,0,0};
	double n5[3]={0,0,0};
	double p1[3]={0.1,0.0,-0.2};
	double p2[3]={0.1,-0.1,-0.4};
	double p3[3]={0.2,0.0,-0.4};
	double p4[3]={0.1,0.1,-0.4};
	double p5[3]={0.2,0.0,-0.6};
	normalplane(p2,p3,p1,n1);
	normalplane(p3,p4,p1,n2);
	normalplane(p4,p3,p5,n3);
	normalplane(p2,p4,p5,n4);
	normalplane(p3,p2,p5,n5);
	//print statements to check normals
	//printf("n%d is x:%.2f, y:%.2f, z:%.2f\n",1,n1[0],n1[1],n1[2]);
	//printf("n%d is x:%.2f, y:%.2f, z:%.2f\n",2,n2[0],n2[1],n2[2]);
	//printf("n%d is x:%.2f, y:%.2f, z:%.2f\n",3,n3[0],n3[1],n3[2]);
	//printf("n%d is x:%.2f, y:%.2f, z:%.2f\n",4,n4[0],n4[1],n4[2]);
	//printf("n%d is x:%.2f, y:%.2f, z:%.2f\n",5,n5[0],n5[1],n5[2]);
	
	glBegin(GL_TRIANGLES);	
	glColor3f(0,1,0);
	glNormal3f(n1[0],n1[1],n1[2]);
	glVertex3d(0.1,0.0,-0.2);
	glVertex3d(0.1,-0.1,-0.4);
	glVertex3d(0.2,0.0,-0.4);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(0,1,0);
	glNormal3d(n2[0],n2[1],n2[2]);
	glVertex3d(0.1,0.0,-0.2);
	glVertex3d(0.2,0.0,-0.4);
	glVertex3d(0.1,0.1,-0.4);
	glEnd();
	
	//code to check normal vector correctness
	//glBegin(GL_LINES);
	//glColor3f(1,0,0);
	//glVertex3d(p3[0],p3[1],p3[2]);
	//glVertex3d(p3[0]+10*n5[0],p3[1]+10*n5[1],p3[2]+10*n5[2]);
	//glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(0,1,0);
	glNormal3d(n3[0],n3[1],n3[2]);
	glVertex3d(0.2,0.0,-0.6);
	glVertex3d(0.2,0.0,-0.4);
	glVertex3d(0.1,0.1,-0.4);
	glEnd();
	//interior back fin part
	glBegin(GL_TRIANGLES);
	glColor3f(0,1,0);
	glNormal3d(n4[0],n4[1],n4[2]);
	glVertex3d(0.2,0.0,-0.6);
	glVertex3d(0.1,0.1,-0.4);
	glVertex3d(0.1,-0.1,-0.4);
	glEnd();
	//far outside left fin part
	glBegin(GL_TRIANGLES);
	glColor3f(0,1,0);
	glNormal3d(n5[0],n5[1],n5[2]);
	glVertex3d(0.2,0.0,-0.6);
	glVertex3d(0.1,-0.1,-0.4);
	glVertex3d(0.2,0.0,-0.4);
	glEnd();
}
//rocket cone
void front()
{
	double n[3]={0,0,0};
	double p1[3]={0.0,0.0,0.75};
	double p2[3]={0.1,0.1,0.4};
	double p3[3]={-0.1,0.1,0.4};
	normalplane(p1,p2,p3,n);
	glBegin(GL_TRIANGLES);
	glColor3f(1,0,1);
	glNormal3d(n[0],n[1],n[2]);
	glVertex3d(0.0,0.0,0.75);
	glVertex3d(0.1,0.1,0.4);
	glVertex3d(-0.1,0.1,0.4);
	glEnd();
}
//
//display rocketbody
//
void rocketbody()
{	
	//side 
	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glNormal3d(1,0,0);
	glVertex3d(0.1,0.1,0.4);
	glVertex3d(0.1,0.1,-0.4);
	glVertex3d(0.1,-0.1,-0.4);
	glVertex3d(0.1,-0.1,0.4);
	glEnd();
	//side 2
	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glNormal3d(-1,0,0);
	glVertex3d(-0.1,0.1,0.4);
	glVertex3d(-0.1,0.1,-0.4);
	glVertex3d(-0.1,-0.1,-0.4);
	glVertex3d(-0.1,-0.1,0.4);
	glEnd();
	//bottom
	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glNormal3d(0,-1,0);
	glVertex3d(-0.1,-0.1,0.4);
	glVertex3d(-0.1,-0.1,-0.4);
	glVertex3d(0.1,-0.1,-0.4);
	glVertex3d(0.1,-0.1,0.4);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glNormal3d(0,1,0);
	glVertex3d(-0.1,0.1,0.4);
	glVertex3d(-0.1,0.1,-0.4);
	glVertex3d(0.1,0.1,-0.4);
	glVertex3d(0.1,0.1,0.4);
	glEnd();
	//back
	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glNormal3d(0,0,-1);
	glVertex3d(0.1,0.1,-0.4);
	glVertex3d(0.1,-0.1,-0.4);
	glVertex3d(-0.1,-0.1,-0.4);
	glVertex3d(-0.1,0.1,-0.4);
	glEnd();
}

//
//  Display the Rocket
//
void Rocket::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   //useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   glPushMatrix();
   rocketbody();
   fin();
   front();
   glPushMatrix();
   glRotatef(90,0,0,1);
   fin();
   front();
   glPopMatrix();
   glPushMatrix();
   glRotatef(180,0,0,1);
   fin();
   front();
   glPopMatrix();
   glPushMatrix();
   glRotatef(270,0,0,1);
   fin();
   front();
   glPopMatrix();
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}

