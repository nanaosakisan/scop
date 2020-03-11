#version 410

layout(location = 0) in vec4 vertex_pos;

void main()
{
    //ajouter normalisation plus tard
    gl_Position = vertex_pos;
}