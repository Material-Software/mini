#pragma once
#include <atomic>
uint32_t CreateVBO(size_t size, void* data);
void BindVBO(const uint32_t& vbo);
void Attrib(const int index, const int numElement, const int stride, const long offset, const uint32_t& vbo);
void SubData(const uint32_t& vbo, size_t offset, size_t size, void* data);
