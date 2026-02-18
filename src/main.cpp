#include "Blocks.h"
#include "Colors.h"
#include "Grid.h"
#include "Resources.h"
#include <raylib.h>
#include <iostream>

int main() {

   Window window(300, 600, "Tetris");
   SetTargetFPS(60);

   Grid grid;
   NormRicky Lblock;

   while(!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(ColorBrightness(cellColorMap[CellState::Empty], 0.04f));

      grid.Draw();
      Lblock.Draw();

      EndDrawing();
   }

   return 0;
}