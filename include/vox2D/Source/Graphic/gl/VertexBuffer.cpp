#include "vox2D/VertexBuffer.h"
#include <GLES3/gl3.h>

uint32_t CreateVBO(size_t size, void* data)
{
	uint32_t result;
	glGenBuffers(1, &result);
	glBindBuffer(GL_ARRAY_BUFFER, result);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	return result;
}

void BindVBO(const uint32_t& vbo)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void Attrib(const int index, const int numElement, const int stride, const long offset, const uint32_t& vbo)
{
	BindVBO(vbo);
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, numElement, GL_FLOAT, GL_FALSE, stride, (void*)offset);
}

void SubData(const uint32_t& vbo, size_t offset, size_t size, void* data)
{
	BindVBO(vbo);
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}
