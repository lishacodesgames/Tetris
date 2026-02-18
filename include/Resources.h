#pragma once

/// @brief to free resources even if game quits unexpectedly
class Window {
public:
   Window(int screenWidth, int screenHeight, const char* title);
   ~Window();
};

class Drawing {
public:
   Drawing();
   ~Drawing();
};