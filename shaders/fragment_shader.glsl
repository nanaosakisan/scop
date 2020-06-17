#version 410

in vec3 fragmentColor;

out vec3 color;

void main()
{
    // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    //FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
    color = fragmentColor;
} 
