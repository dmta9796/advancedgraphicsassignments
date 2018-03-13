//displacement
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
   float x= gl_TexCoord[0].x-0.5;
   float y= gl_TexCoord[0].y-0.5;
   float radius= sqrt(x*x+y*y);
   float angle= atan(y/x);
   vec2 position=radius*vec2(cos(angle),sin(angle));
   //float len=length(position);
   gl_FragColor = texture2D(img,position);
}
