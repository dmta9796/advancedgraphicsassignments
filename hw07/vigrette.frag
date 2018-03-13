//Vigrette
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
   vec2 position=(gl_TexCoord[0].st)-vec2(0.5);
   float len=length(position);
   gl_FragColor =  vec4(texture2D(img,gl_TexCoord[0].st).xyz*(1.0-len),1.0);
}
