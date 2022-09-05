#pragma once
#include <atomic>
#include "Macro.h"
#include <glm/glm.hpp>
#include <GLES3/gl3.h>

uint32_t CreateShader(const char* vsFile, const char* fsFile);
int GetUniform(uint32_t shaderProgram, const char* name);
void ShaderSetFloat(uint32_t shaderProgram, const char* name, float value);
void ShaderSetMatrix(uint32_t shaderProgram, const char* name, glm::mat4 value);
void ShaderSetVec3(uint32_t shaderProgram, const char* name, glm::vec3 value);
