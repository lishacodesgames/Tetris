#include "grid.h"
#include <raylib.h>

int main() {

   InitWindow(400, 800, "Raylib Template");
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