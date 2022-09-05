#pragma once
#include <SDL2/SDL_opengles2.h>
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 Pos;
	glm::vec2 Tex;
	glm::vec4 Col;
};

Vertex setVertex(glm::vec3 Pos, glm::vec2 Tex, glm::vec4 Col);
void vxClearBackground(float r, float g, float b, float a);
void Draw(uint32_t vbo, uint32_t ebo, uint32_t shaderProgram, uint32_t numIndex);
void Draw(uint32_t vbo, uint32_t shaderProgram, uint32_t numVertex);
