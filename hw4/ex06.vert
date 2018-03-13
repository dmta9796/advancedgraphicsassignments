#version 400 core

//  Transformation matrices
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat3 NormalMatrix;
//light parameters
uniform vec3 lpos;
uniform vec4 EyePosition;
//material parameters
uniform vec3 Ambient;
uniform vec3 Emission;
uniform vec3 Diffuse;
uniform vec3 Specular;
uniform float Shininess;

//  Vertex attributes (input)
layout(location = 0) in vec4 Vertex;
layout(location = 1) in vec3 Color;
layout(location = 2) in vec3 Normal;
layout(location = 3) in vec2 tex_coord;

//  Output to next shader
out vec3 FrontColor;
out vec2 texcoord;

void main()
{	
   //  P is the vertex coordinate on body
   vec3 P = vec3(ModelViewMatrix * Vertex);
   //  N is the object normal at P
   vec3 N = normalize(NormalMatrix * Normal);
   //  Light Position for light 0
   vec3 LightPos = vec3(ModelViewMatrix*vec4(lpos,1.0));
   //  L is the light vector
   vec3 L = normalize(LightPos - P);
   //compute EyeDirection
   vec3 V=normalize(vec3(EyePosition*Vertex));
   //  Emission and ambient color
   vec3 color = Emission+ Ambient; //ambient and emission
   //compute HalfVector Lightposition+EyeVector;
   vec3 HalfVector= normalize(L+V);
   //diffuse light
   float Id=dot(L,N);
   if(Id>0.0)
   {
        color+= Id*Diffuse; //diffuse light
      float Is=dot(N,HalfVector);
      if (Is>0.0) color += pow(Is,Shininess)*Specular; //spectral light

   }
   //compute texture coords for fragshader
   texcoord=tex_coord;

   //  Pass colors to fragment shader (will be interpolated)
   FrontColor = Color*color;//color;//*Color;
   //  Set transformed vertex location
   gl_Position =  ProjectionMatrix * ModelViewMatrix * Vertex;
}
