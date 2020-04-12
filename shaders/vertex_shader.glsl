#version 410

layout(location = 0) in vec4 vertex_pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    //ajouter normalisation plus tard
    // gl_Position = (projection * view * model) * vertex_pos;
    gl_Position = vertex_pos;
}