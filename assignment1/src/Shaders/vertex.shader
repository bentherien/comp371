// Shader code taken from LearnOpenGl.com (will likely be heavily changed so we can delete this comment)

#version 440
layout(location = 0) in vec3 aPos;
//layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 translation;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	//TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}