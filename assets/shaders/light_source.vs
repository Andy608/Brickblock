#version 330 core
layout (location = 0) in vec3 vertexPos;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 transformMatrix;

void main()
{
	mat4 transformation = projectionMatrix * viewMatrix * transformMatrix;
	vec4 position = vec4(vertexPos, 1.0);

    gl_Position = transformation * position;
}   