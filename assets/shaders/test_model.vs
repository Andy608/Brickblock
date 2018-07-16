#version 330 core
layout (location = 0) in vec3 vertexPos;
//layout (location = 1) in vec2 texCoords;
layout (location = 1) in vec3 normals;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 transformMatrix;
uniform mat3 normalMatrix;
uniform float time;

uniform vec3 lightPos;

out vec3 out_normal;
out vec3 out_fragPos;
out vec3 out_lightPos;

float Speed = 0.5;

void main()
{
	//Position
	mat4 viewTransform = viewMatrix * transformMatrix;

	vec4 viewPos = viewTransform * vec4(vertexPos, 1.0);

    gl_Position = projectionMatrix * viewPos;

	//Lighting

	out_normal = normalMatrix * normals;
	out_fragPos = viewPos.xyz;
	out_lightPos = (viewMatrix * vec4(lightPos, 1.0)).xyz;
}   