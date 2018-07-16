#version 330 core

in vec2 out_textureCoords;
//in vec4 out_color;
in vec3 out_normal;
in vec3 out_fragPos;
in vec3 out_lightPos;

vec4 out_color;

//uniform sampler2D textureSampler;

uniform vec3 modelColor;
uniform vec3 lightColor;

out vec4 FragColor;

float AmbientStrength = 0.2;
float SpecularStrength = 0.5;

void main()
{
	//Ambient
	vec3 ambientLight = AmbientStrength * lightColor;

	//Diffuse
	vec3 norm = normalize(out_normal);
	vec3 vertexToLight = normalize(out_lightPos - out_fragPos);
	float dotAngle = max(dot(norm, vertexToLight), 0.0);
	vec3 diffuseLight = dotAngle * lightColor;
	
	//Specular
	vec3 vertexToView = normalize(-out_fragPos);
	vec3 reflection = reflect(-vertexToLight, norm);
	float spec = pow(max(dot(vertexToView, reflection), 0.0), 32);
	vec3 specular = SpecularStrength * spec * lightColor;

	vec3 result = (ambientLight + diffuseLight + specular) * modelColor;

	out_color = vec4(result, 1.0);

	FragColor = out_color;
	//FragColor = texture(textureSampler, vec2(1.0));
    //FragColor = texture(textureSampler, out_textureCoords);
}