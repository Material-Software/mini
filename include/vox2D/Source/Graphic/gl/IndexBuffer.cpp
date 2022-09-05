#include "vox2D/IndexBuffer.h"
#include <GLES3/gl3.h>

uint32_t CreateEBO(size_t size, void* data)
{
	uint32_t result;
	glGenBuffers(1, &result);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, result);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	return result;
}

void BindEBO(const uint32_t& ebo)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}

