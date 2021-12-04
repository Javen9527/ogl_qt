#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexcord;

out vec2 Texcord;

uniform mat4 model;

void main()
{
    gl_Position = model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    Texcord = aTexcord;
}
