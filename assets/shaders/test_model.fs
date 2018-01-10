#version 330 core

in vec2 out_textureCoords;
in vec4 out_color;

uniform sampler2D textureSampler;

out vec4 FragColor;

void main()
{
	FragColor = out_color;
	//FragColor = texture(textureSampler, vec2(1.0));
    //FragColor = texture(textureSampler, out_textureCoords);
}