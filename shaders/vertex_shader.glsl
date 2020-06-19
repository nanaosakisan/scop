#version 410

layout(location = 0) in vec4 vertex_pos;
layout(location = 1) in vec3 vertexColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 fragmentColor;

void main()
{
    //ajouter normalisation plus tard
    gl_Position = (projection * view * model) * vertex_pos;
    fragmentColor = vertexColor;
}