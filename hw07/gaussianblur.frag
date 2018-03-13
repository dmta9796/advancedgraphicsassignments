//enlarge image
uniform float dX;
uniform float dY;
uniform sampler2D img;

vec4 sample(float dx,float dy)
{
   return texture2D(img,gl_TexCoord[0].st+vec2(dx,dy));
}

void main()
{
   float x=0.5*gl_TexCoord[0].x; //magnify image by four times
   float y=0.5*gl_TexCoord[0].y; //magnify image by four times
   vec2 position=vec2(x,y);
   //interpolate image between positions
   gl_FragColor = texture2D(img,position);
}
