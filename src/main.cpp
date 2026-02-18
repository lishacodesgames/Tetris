#include "grid.h"
#include <raylib.h>
#include <iostream>

int main() {
   constexpr int screenWidth = 300; // note these numbers are called as magic numbers in Grid::Draw()
   constexpr int screenHeight = 600; // if you change these, go and change those too

   InitWindow(screenWidth, screenHeight, "Tetris");
   SetTargetFPS(60);

   Grid grid;

   while(!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(BLUE);

      grid.Draw();

      EndDrawing();
   }

   CloseWindow();
   return 0;
}