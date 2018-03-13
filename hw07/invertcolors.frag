// invert color

uniform sampler2D img;

void main()
{
   vec3 colors= vec3(texture2D(img,gl_TexCoord[0].st));
   float x=colors.x;
   float y=colors.y;
   float z=colors.z;
   //vec3 invertcolors=(1.0-colors);
   gl_FragColor=vec4(1.0-x,1.0-y,1.0-z,1.0);
   //gl_FragColor = texture2D(img,gl_TexCoord[0].st);
}
