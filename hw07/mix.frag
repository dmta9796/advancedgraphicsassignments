// Blur
//   1 2 1
//   2 1 2   / 13
//   1 2 1

uniform float dX;
uniform float dY;
uniform sampler2D img;

vec4 sample(float dx,float dy)
{
   return texture2D(img,gl_TexCoord[0].st+vec2(dx,dy));
}

void main()
{
   //blur
   float one = 1.0/11.0;
   float two = 1.5/11.0;
   vec4 blur = one*sample(-dX,+dY) + two*sample(0.0,+dY) + one*sample(+dX,+dY)
                 + two*sample(-dX,0.0) + one*sample(0.0,0.0) + two*sample(+dX,0.0)
                 + one*sample(-dX,-dY) + two*sample(0.0,-dY) + one*sample(+dX,-dY);
   //sabel
   vec4 H = -sample(-dX,+dY) - 2.0*sample(0.0,+dY) - sample(+dX,+dY)
            +sample(-dX,-dY) + 2.0*sample(0.0,-dY) + sample(+dX,-dY);

   vec4 V =     sample(-dX,+dY)  -     sample(+dX,+dY)
          + 2.0*sample(-dX,0.0)  - 2.0*sample(+dX,0.0)
          +     sample(-dX,-dY)  -     sample(+dX,-dY);

   vec4 sabel = sqrt(H*H+V*V);

   //some odd mix
   //gl_FragColor=mix(sabel,blur,0.5);
   gl_FragColor = sqrt(sabel*sabel+blur*blur);

}
