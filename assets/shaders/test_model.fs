#version 330 core
in vec2 out_textureCoords;
uniform sampler2D textureSampler;

out vec4 FragColor;

void main()
{
    FragColor = texture(textureSampler, out_textureCoords);
}