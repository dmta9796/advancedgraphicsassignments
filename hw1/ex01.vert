// Vertex shader

uniform float time;
uniform float xpos;
uniform float ypos;
uniform float zpos;
uniform float wpos;
varying vec4 foo;

void main()
{
   //  Set vertex coordinates
   vec4 pos =  gl_Vertex ;
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;//position transformation
   
   //have color depend on position
   foo= ((gl_Position+1.0)/2.0)/gl_Position.w;//color based on location of cube and to transform the position [-1,1] ->  color[0,1]
}
