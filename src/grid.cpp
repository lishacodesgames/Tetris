#include "Grid.h"
#include "Colors.h"
#include <raylib.h>
#include <vector>
#include <map>

#include <iostream> // for testing TODO remove later

Grid::Grid() {
   rows = 20;
   columns = 10;
   cellSize = 30;

   // all cells in grid = 0
   for(auto& row : grid) {
      for(CellState& cell : row) {
         cell = CellState::Empty;
      }
   }
}

void Grid::Draw() {
   // permanently placed blocks
   for (int row = 0; row < rows; row++) {
      for (int col = 0; col < columns; col++) {
         DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, cellColorMap[ grid.at(row).at(col) ]);
      }
   }
}