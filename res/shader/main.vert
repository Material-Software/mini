#version 300 es
layout(location = 0)in vec3 aPos;
layout(location = 1)in vec2 aTex;
layout(location = 2)in vec4 aCol;
out vec4 color;
out vec2 texCoord;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
void main()
{
	color = aCol;
	texCoord = aTex;
	gl_Position = proj * view * model * vec4(aPos, 1.f);
}
