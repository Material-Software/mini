#pragma once
#include <atomic>
uint32_t CreateEBO(size_t size, void* data);
void BindEBO(const uint32_t& ebo);
