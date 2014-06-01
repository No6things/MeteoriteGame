#pragma once
#ifndef CALLBACKS_H
#define CALLBACKS_H

void Reshape(int w, int h);
void Display();
void Keyboard(unsigned char key, int x, int y);
void MouseButton(int btn, int state, int x, int y);
void MouseMotion(int x, int y);
void MousePosition(int x, int y);
void Callbacks();

#endif