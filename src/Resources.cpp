#include "Resources.h"
#include <raylib.h>

Window::Window(int screenWidth, int screenHeight, const char* title) { 
   InitWindow(screenWidth, screenHeight, title); 
}
Window::~Window() { CloseWindow(); }

Drawing::Drawing() { BeginDrawing(); }
Drawing::~Drawing() { EndDrawing(); }