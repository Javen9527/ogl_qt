#version 330 core

in vec2 Texcord;
out vec4 FragColor;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main()
{
    FragColor = mix(texture(texture0, Texcord), texture(texture1, Texcord), 0.5);
}
