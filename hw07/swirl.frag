//swirl
uniform float dX;
uniform float dY;
uniform sampler2D img;
uniform vec2 resolution;

vec4 sample(float dx,float dy)
{
   return texture2D(img,gl_TexCoord[0].st+vec2(dx,dy));
}

void main()
{
   float x= gl_TexCoord[0].x;
   float y= 1.0-(gl_TexCoord[0].y);
   mat2 rot;
   float radius=sqrt(x*x+y*y);
   float angle=atan(y/x);
   rot[0]=vec2(cos(0.1),-sin(0.1));
   rot[1]=vec2(sin(0.1),cos(0.1));
   vec2 position=rot*vec2(x,y);
   //float len=length(position);
   gl_FragColor = texture2D(img,position);
}
