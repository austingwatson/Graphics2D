#version 330 core
layout (location = 0) in vec3 pos;

out vec4 fragColor;

uniform vec4 color;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(pos, 1.0);
    fragColor = color;
}