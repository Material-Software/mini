#pragma once

void vxInit(int width, int height, const char* title);
void vxTerminate();
void vxSwapBuffer();
void vxSetWindowTitle(const char* title);
void vxGetWindowWidth(int& width, int& height);
