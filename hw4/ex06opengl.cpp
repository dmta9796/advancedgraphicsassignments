//
//  OpenGL widget
//
#include "ex06opengl.h"

//
//  Constructor
//
Ex06opengl::Ex06opengl(QWidget* parent)
    : CUgl(parent)
{
}

//
//  Cube Vertexes
//
const int cube_size=36;
const float cube_data[] =  // Vertex data
{
//  X  Y  Z  W   Nx Ny Nz    R G B   s t
   //  Front
   +1,+1,+1,+1,   0, 0,+1,   1,0,0,  1,1,
   -1,+1,+1,+1,   0, 0,+1,   1,0,0,  0,1,
   +1,-1,+1,+1,   0, 0,+1,   1,0,0,  1,0,
   -1,+1,+1,+1,   0, 0,+1,   1,0,0,  0,1,
   +1,-1,+1,+1,   0, 0,+1,   1,0,0,  1,0,
   -1,-1,+1,+1,   0, 0,+1,   1,0,0,  0,0,
   //  Back
   -1,-1,-1,+1,   0, 0,-1,   0,0,1,  1,0,
   +1,-1,-1,+1,   0, 0,-1,   0,0,1,  0,0,
   -1,+1,-1,+1,   0, 0,-1,   0,0,1,  1,1,
   +1,-1,-1,+1,   0, 0,-1,   0,0,1,  0,0,
   -1,+1,-1,+1,   0, 0,-1,   0,0,1,  1,1,
   +1,+1,-1,+1,   0, 0,-1,   0,0,1,  0,1,
   //  Right
   +1,+1,+1,+1,  +1, 0, 0,   1,1,0,  0,1,
   +1,-1,+1,+1,  +1, 0, 0,   1,1,0,  0,0,
   +1,+1,-1,+1,  +1, 0, 0,   1,1,0,  1,1,
   +1,-1,+1,+1,  +1, 0, 0,   1,1,0,  0,0,
   +1,+1,-1,+1,  +1, 0, 0,   1,1,0,  1,1,
   +1,-1,-1,+1,  +1, 0, 0,   1,1,0,  1,0,
   //  Left
   -1,+1,+1,+1,  -1, 0, 0,   0,1,0,  1,1,
   -1,+1,-1,+1,  -1, 0, 0,   0,1,0,  0,1,
   -1,-1,+1,+1,  -1, 0, 0,   0,1,0,  1,0,
   -1,+1,-1,+1,  -1, 0, 0,   0,1,0,  0,1,
   -1,-1,+1,+1,  -1, 0, 0,   0,1,0,  1,0,
   -1,-1,-1,+1,  -1, 0, 0,   0,1,0,  0,0,
   //  Top
   +1,+1,+1,+1,   0,+1, 0,   0,1,1,  1,0,
   +1,+1,-1,+1,   0,+1, 0,   0,1,1,  1,1,
   -1,+1,+1,+1,   0,+1, 0,   0,1,1,  0,0,
   +1,+1,-1,+1,   0,+1, 0,   0,1,1,  1,1,
   -1,+1,+1,+1,   0,+1, 0,   0,1,1,  0,0,
   -1,+1,-1,+1,   0,+1, 0,   0,1,1,  0,1,
   //  Bottom
   -1,-1,-1,+1,   0,-1, 0,   1,0,1,  0,0,
   +1,-1,-1,+1,   0,-1, 0,   1,0,1,  1,0,
   -1,-1,+1,+1,   0,-1, 0,   1,0,1,  0,1,
   +1,-1,-1,+1,   0,-1, 0,   1,0,1,  1,0,
   -1,-1,+1,+1,   0,-1, 0,   1,0,1,  0,1,
   +1,-1,+1,+1,   0,-1, 0,   1,0,1,  1,1,
   };

//
//  Initialize
//
void Ex06opengl::initializeGL()
{
   // Texture
   tex = new QOpenGLTexture(QImage(":/crate.png").mirrored());

   //  Load shaders
   addShader(":/ex06.vert",":/ex06.frag");

   //  Cube vertex buffer object
   //  Copy data to vertex buffer object
   cube_buffer.create();
   cube_buffer.bind();
   cube_buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
   cube_buffer.allocate(sizeof(cube_data));
   cube_buffer.write(0,cube_data,sizeof(cube_data));
   //  Unbind this buffer
   cube_buffer.release();
}

//
//  Draw the window
//
void Ex06opengl::paintGL()
{
   //  Clear screen and Z-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   //  Set projection for fixed pipeline
   doModelViewProjection();

   //  Set light
   QVector3D lpos = doLight();
   Q_UNUSED(lpos);  // Suppress warning since lpos is not used yet

   //  Fixed pipeline
   if (mode==0)
   {
      //  Enable textures
      glEnable(GL_TEXTURE_2D);
      tex->bind();

      //  Enabe arrays
      glEnableClientState(GL_VERTEX_ARRAY);
      glEnableClientState(GL_NORMAL_ARRAY);
      glEnableClientState(GL_COLOR_ARRAY);
      glEnableClientState(GL_TEXTURE_COORD_ARRAY);

      //  Set pointers
      
      glVertexPointer  (4,GL_FLOAT,12*sizeof(GLfloat),cube_data);
      glNormalPointer  (  GL_FLOAT,12*sizeof(GLfloat),cube_data+4);
      glColorPointer   (3,GL_FLOAT,12*sizeof(GLfloat),cube_data+7);
      glTexCoordPointer(2,GL_FLOAT,12*sizeof(GLfloat),cube_data+10);

      //  Draw the cube slightly offset
      glPushMatrix();
      glTranslated(0,0,0.5);
      glDrawArrays(GL_TRIANGLES,0,cube_size);
      glPopMatrix();

      //  Disable arrays
      glDisableClientState(GL_VERTEX_ARRAY);
      glDisableClientState(GL_NORMAL_ARRAY);
      glDisableClientState(GL_COLOR_ARRAY);
      glDisableClientState(GL_TEXTURE_COORD_ARRAY);

      //  Disable textures and lighting
      glDisable(GL_TEXTURE_2D);
      glDisable(GL_LIGHTING);
   }
   //  OpenGL 4 style shaders
   else
   {
     //  Create Projection matrix
      QMatrix4x4 proj;
      proj.setToIdentity();
      float asp = width() / (float)height();
      if (fov)
         proj.perspective(fov,asp,dim/4,4*dim);
      else
         proj.ortho(-dim*asp, +dim*asp, -dim, +dim, -dim, +dim);
      //  Create View matrix
      QMatrix4x4 view;
      if (fov) view.translate(0,0,-2*dim);
      view.rotate(ph,1,0,0);
      view.rotate(th,0,1,0);
      //  Create ModelView matrix
      QMatrix4x4 mv = view;
      mv.translate(0,0,0.5);

      //set Normal Matrix
      QMatrix3x3 NormalMatrix=mv.normalMatrix();

      //Material Properties
      QVector3D Ambient=QVector3D(0.3,0.3,0.3);
      QVector3D Emission=QVector3D(0.0,0.0,0.0);
      QVector3D Diffuse=QVector3D(1.0,1.0,1.0);
      QVector3D Specular=QVector3D(1.0,1.0,1.0);
      float Shininess=4.0;
      //EyePosition
      QVector4D EyePosition=view*QVector4D(0.0,0.0,0.0,1.0);//view matrix to get camera position

      // Enable shader
      shader[mode]->bind();
      //  Set Modelview and Projection Matrix
      shader[mode]->setUniformValue("ProjectionMatrix",proj);
      shader[mode]->setUniformValue("ModelViewMatrix",mv);
      shader[mode]->setUniformValue("NormalMatrix",NormalMatrix);
      //light parameters
      shader[mode]->setUniformValue("lpos",lpos);
      shader[mode]->setUniformValue("EyePosition",EyePosition);

      //material parameters
      shader[mode]-> setUniformValue("Ambient",Ambient);
      shader[mode]-> setUniformValue("Emission",Emission);
      shader[mode]-> setUniformValue("Diffuse",Diffuse);
      shader[mode]-> setUniformValue("Specular",Specular);
      shader[mode]-> setUniformValue("Shininess",Shininess);
      //load texture
      tex->bind();
      //shader[mode]-> setUniformValue("tex",tex);


      //  Select cube buffer
      cube_buffer.bind();
      //   Attribute 0: vertex coordinate (vec4) at offset 0
      shader[mode]->enableAttributeArray(0);
      shader[mode]->setAttributeBuffer(0,GL_FLOAT,0,4,12*sizeof(float));
      //   Attribute 1:  vertex color (vec3) offset 7 floats
      shader[mode]->enableAttributeArray(1);
      shader[mode]->setAttributeBuffer(1,GL_FLOAT,7*sizeof(float),3,12*sizeof(float));
      //   Attribute 2:  Normal Vector (vec3) offset 4 floats
      shader[mode]->enableAttributeArray(2);
      shader[mode]->setAttributeBuffer(2,GL_FLOAT,4*sizeof(float),3,12*sizeof(float));
      //   Attribute 3:  Texture coords (vec2) offset 10 floats
      shader[mode]->enableAttributeArray(3);
      shader[mode]->setAttributeBuffer(3,GL_FLOAT,10*sizeof(float),2,12*sizeof(float));

      // Draw the cube
      glDrawArrays(GL_TRIANGLES,0,cube_size);

      //  Disable vertex arrays
      shader[mode]->disableAttributeArray(0);
      shader[mode]->disableAttributeArray(1);
      shader[mode]->disableAttributeArray(2);
      shader[mode]->disableAttributeArray(3);

      //  Unbind this buffer
      cube_buffer.release();

      // Back to fixed pipeline
      shader[mode]->release();
   }

   //  Axes for reference
   glColor3f(1,1,1);
   glBegin(GL_LINES);
   glVertex3f(0,0,0);
   glVertex3f(2,0,0);
   glVertex3f(0,0,0);
   glVertex3f(0,2,0);
   glVertex3f(0,0,0);
   glVertex3f(0,0,2);
   glEnd();
}
