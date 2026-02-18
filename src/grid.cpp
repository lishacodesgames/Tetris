#include "grid.h"
#include <raylib.h>
#include <vector>
#include <unordered_map>

#include <iostream> // for testing TODO remove later

Grid::Grid() {
   rows = 20;
   columns = 10;
   cellSize = 40;

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

void Grid::Print() {
   for(const auto& row : grid) {
      for(const CellState& cell : row) {
         std::cout << static_cast<int>(cell) << " ";
      }
      std::cout << "\n";
   }
}

void Grid::Draw() {
   for (int row = 0; row < rows; row++) {
      for (int col = 0; col < columns; col++) {
         DrawRectangle(col * cellSize, row * cellSize, cellSize, cellSize, cellColorMap[grid[row][col]]);
      }
   }
}