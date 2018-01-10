#version 330 core
layout (location = 0) in vec3 vertexPos;
layout (location = 1) in vec2 texCoords;
layout (location = 2) in vec3 normals;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 transformMatrix;
uniform float time;

out vec2 out_textureCoords;
out vec4 out_color;

float speed = 0.5;

void main()
{
	mat4 rotationMat = mat4(
	cos(speed * time), 0.0, sin(speed * time), 0.0,
	0.0, 1.0, 0.0, 0.0,
	-sin(speed * time), 0.0, cos(speed * time), 0.0,
	0.0, 0.0, 0.0, 1.0
	);

	mat4 transformation = projectionMatrix * viewMatrix * transformMatrix;
	vec4 position = vec4(vertexPos, 1.0);

	//position.x += sin(time);

    gl_Position = transformation * /*rotationMat **/ position;
    out_textureCoords = texCoords;
	out_color = vec4(vertexPos, 1.0);
}   