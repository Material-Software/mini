#include "vox2D/Texture.h"
#include <SDL2/SDL_image.h>
#include <GLES3/gl3.h>

uint32_t LoadTexture(int sampler2D, int format, const char* path)
{
	SDL_Surface* surface = IMG_Load(path);
	uint32_t texture;
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0 + sampler2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);
	return texture;
}
