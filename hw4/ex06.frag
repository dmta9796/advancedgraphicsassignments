#version 400 core
uniform sampler2D tex;
//  Input from previous shader
in vec3 FrontColor;
in vec2 texcoord;

//  Fragment color
layout (location=0) out vec4 Fragcolor;

void main()
{
   Fragcolor = vec4(FrontColor,1.0)*texture2D(tex,texcoord);
}
