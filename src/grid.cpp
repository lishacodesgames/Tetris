#include "Grid.h"
#include "Resources.h"
#include <raylib.h>
#include <vector>
#include <unordered_map>

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

   // cell-color map
   cellColorMap = {
      {CellState::Empty, colorValue.Empty},
      {CellState::Hero, colorValue.Hero},
      {CellState::Teewee, colorValue.Teewee},
      {CellState::Smashboy, colorValue.Smashboy},
      {CellState::NormRicky, colorValue.NormRicky},
      {CellState::AutRicky, colorValue.AutRicky},
      {CellState::Snake, colorValue.Snake},
      {CellState::Znake, colorValue.Znake}
   };
}

void Grid::Draw() {
   // permanently placed blocks
   for (int row = 0; row < rows; row++) {
      for (int col = 0; col < columns; col++) {
         DrawRectangle(col * cellSize, row * cellSize, cellSize, cellSize, cellColorMap[ grid.at(row).at(col) ]);
      }
   }
   
   // cannot do in earlier loop, or the rectangles will draw over the lines
   Vector2 start, end;
   Color gridLines = ColorBrightness(colorValue.Empty, 0.04f);

   for (int col = 1; col < columns; col++) {
      start = {(float)(col * cellSize), 0};
      end = {(float)(col * cellSize), (float)GetScreenHeight()};
      DrawLineEx(start, end, 2, gridLines); 
   }

   for (int row = 1; row < rows; row++) { 
      start = {0, (float)(row * cellSize)};
      end = {(float)GetScreenWidth(), (float)(row * cellSize)};
      DrawLineEx(start, end, 2, gridLines);
   }
}