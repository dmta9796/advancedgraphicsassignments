#version 400 core
//  Transformation matrices
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;

//inputs
layout(location = 0) in vec4 Vertex; // works correctly as the pos changes color
layout(location = 1) in vec3 color;    //vertexcolor draws a cube normally
layout(location = 2) in vec2 texcoord;

//pass to fragment shader
varying vec2 TexCoord;
varying vec3 Color;

void main(void)
{
    Color=color;
    TexCoord = texcoord;
    gl_Position = ProjectionMatrix*ModelViewMatrix*Vertex;
}
