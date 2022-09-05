#include "vox2D/Render.h"

void Draw(uint32_t vbo, uint32_t ebo, uint32_t shaderProgram, uint32_t numIndex)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glUseProgram(shaderProgram);
	glDrawElements(GL_TRIANGLES, numIndex, GL_UNSIGNED_INT, 0);
}
void Draw(uint32_t vbo, uint32_t shaderProgram, uint32_t numVertex)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLES, 0, numVertex);
}



Vertex setVertex(glm::vec3 Pos, glm::vec2 Tex, glm::vec4 Col)
{
	Vertex result;
	result.Pos = Pos;
	result.Tex = Tex;
	result.Col = Col;
	return result;
}


void vxClearBackground(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}
