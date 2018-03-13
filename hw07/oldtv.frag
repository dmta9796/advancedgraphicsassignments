// old tv effect

uniform float time;
uniform vec2 resolution;
uniform float dX;
uniform float dY;
uniform sampler2D img;

vec4 sample(float dx,float dy)
{
   return texture2D(img,gl_TexCoord[0].st+vec2(dx,dy));
}

void main()
{
   //shifting
   float x= gl_TexCoord[0].x;
   float y= gl_TexCoord[0].y-0.5*time;
   vec2 coord=vec2(x,y);

   //blur
   float one = 1.0/13.0;
   float two = 2.0/13.0;
   vec4 blur    = one*sample(-dX*x,+dY*y) + two*sample(0.0,+dY*y) + one*sample(+dX*x,+dY*y)
                + two*sample(-dX*x,0.0) + one*sample(0.0,0.0) + two*sample(+dX*x,0.0)
                + one*sample(-dX*x,-dY*y) + two*sample(0.0,-dY*y) + one*sample(+dX*x,-dY*y);

   //vigrette
   vec2 position=(gl_TexCoord[0].st)-vec2(0.5);
   float len=length(position);
   vec4 Colors=vec4(texture2D(img,coord).xyz*(1.0-len),1.0);

   //black and white
   float r=Colors.r;
   float g=Colors.g;
   float b=Colors.b;
   float collen=sqrt(r*r+g*g+b*b);
   vec3 Color=vec3(collen,collen,collen);

   //scanline
   vec2 uv = (gl_FragCoord.xy*coord) / resolution.xy;
   float yy = mod(floor(uv.y * resolution.y / 4.0), 2.0);
   vec3 scanline = Color-vec3(yy,yy,yy);


   gl_FragColor = vec4(scanline*Color,1.0);
   //gl_FragColor = texture2D(img,gl_TexCoord[0].st);
}
