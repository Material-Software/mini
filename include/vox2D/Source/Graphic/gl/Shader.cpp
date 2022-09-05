#include "vox2D/Shader.h"
#include <GLES3/gl3.h>
#include <glm/gtc/type_ptr.hpp>

uint32_t CreateShader(const char* vsFile, const char* fsFile)
{
	FILE* vsFP = fopen(vsFile, "r");
	FILE* fsFP = fopen(fsFile, "r");
	if(vsFP == NULL)
	{
		printf("file not found: %s", vsFile);
		return 0;
	}
	if(fsFP == NULL)
	{
		printf("file not found: %s", fsFile);
		return 0;
	}
	fseek(vsFP, 0L, SEEK_END);
	fseek(fsFP, 0L, SEEK_END);
	size_t vsSize = ftell(vsFP);
	size_t fsSize = ftell(fsFP);
	fseek(vsFP, 0L, SEEK_SET);
	fseek(fsFP, 0L, SEEK_SET);
	char vsSource[vsSize];
	char fsSource[fsSize];
	fread(vsSource, vsSize, 1, vsFP);
	fread(fsSource, fsSize, 1, fsFP);
	vsSource[vsSize-1] = 0;
	fsSource[fsSize-1] = 0;
	const char* vertexShaderSource = vsSource;
	const char* fragmentShaderSource = fsSource;
	uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, 0);
	glCompileShader(vertexShader);
	uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, 0);
	glCompileShader(fragmentShader);
	uint32_t shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, 512, 0, infoLog);
		logl("[VERTEX SHADER]: " << infoLog);
		glGetShaderInfoLog(fragmentShader, 512, 0, infoLog);
		logl("[FRAGMENT SHADER]: " << infoLog);
		return 0;
	}


	return shaderProgram;

}
int GetUniform(uint32_t shaderProgram, const char* name)
{
	return glGetUniformLocation(shaderProgram, name); 
}
void ShaderSetFloat(uint32_t shaderProgram, const char* name, float value)
{
	glUseProgram(shaderProgram);
	int loc = GetUniform(shaderProgram, name);
	if(loc < 0)
		printf("uniform not found: %s\n", name);
	glUniform1f(loc, value);
}
void ShaderSetMatrix(uint32_t shaderProgram, const char* name, glm::mat4 value)
{
	glUseProgram(shaderProgram);
	int loc = GetUniform(shaderProgram, name);
	if(loc < 0)
		printf("uniform not found: %s\n", name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));

}
void ShaderSetVec3(uint32_t shaderProgram, const char* name, glm::vec3 value)
{
	glUseProgram(shaderProgram);
	int loc = GetUniform(shaderProgram, name);
	if(loc < 0)
		printf("uniform not found: %s\n", name);
	glUniform3f(loc, value.x, value.y, value.z);

}

