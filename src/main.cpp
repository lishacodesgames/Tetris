#include "grid.h"
#include <raylib.h>
#include <iostream>

int main() {

   InitWindow(300, 600, "Tetris");
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