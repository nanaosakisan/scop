#version 410

layout(location = 0) in vec3 vertex_pos;

void main()
{
    //ajouter normalisation plus tard
    gl_Position = vec4(vertex_pos.x, vertex_pos.y, vertex_pos.z, 1.0);
}