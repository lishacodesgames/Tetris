#include "Grid.h"
#include "Resources.h"
#include <raylib.h>
#include <iostream>

int main() {

   Window window(300, 600, "Tetris");
   SetTargetFPS(60);

   Grid grid;

   // testing colors
   grid.grid.at(9).at(2) = static_cast<CellState>(1);
   grid.grid.at(9).at(3) = static_cast<CellState>(2);
   grid.grid.at(9).at(4) = static_cast<CellState>(3);
   grid.grid.at(9).at(5) = static_cast<CellState>(4);
   grid.grid.at(9).at(6) = static_cast<CellState>(5);
   grid.grid.at(9).at(7) = static_cast<CellState>(6);
   grid.grid.at(9).at(8) = static_cast<CellState>(7);

   while(!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(BLUE);

      grid.Draw();

      EndDrawing();
   }

   return 0;
}