// Fragment shader

uniform float time;
uniform float xpos;
uniform float ypos;
uniform float zpos;
uniform float wpos;
varying vec4 foo;

void main()
{
   //gl_FragColor = foo+vec4(sin(time),cos(time),0.0,0.0);
   gl_FragColor = foo;//+vec4(xpos,ypos,zpos,wpos);
}
