#include <Precompiled.h>
#include <raylib.h>
#include <vector>
#include "Grid.h"
#include "Colors.h"
#include "Position.h"

Grid::Grid() {
   m_rows = 20;
   m_columns = 10;
   m_cellSize = 30;

   // all cells in grid <- 0
   for(auto& row : grid) {
      for(CellType& cell : row) {
         cell = CellType::Empty;
      }
   }
}

void Grid::Draw() {
   for (int row = 0; row < m_rows; row++) {
      for (int col = 0; col < m_columns; col++) {
         DrawRectangle(col * m_cellSize + 1, row * m_cellSize + 1, m_cellSize - 1, m_cellSize - 1, cellColorMap[ grid.at(row).at(col) ]);
      }
   }
}

Grid::OutOfBounds Grid::checkBounds(const Position& cell) {
   if(cell.row < 0)
      return OutOfBounds::Top;
   else if(cell.col >= m_columns)
      return OutOfBounds::Right;
   else if(cell.row >= m_rows)
      return OutOfBounds::Bottom;
   else if(cell.col < 0)
      return OutOfBounds::Left;
   else 
      return OutOfBounds::Inside;
}