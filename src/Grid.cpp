#include <Precompiled.h>
#include <raylib.h>
#include <vector>
#include "Grid.h"
#include "Colors.h"
#include "Position.h"

void Grid::Draw() {
   for (int row = 0; row < m_rows; row++) {
      for (int col = 0; col < m_columns; col++) {
         DrawRectangle(
            col * cellSize + 1, row * cellSize + 1, 
            cellSize - 1, cellSize - 1, 
            cellColorMap[ grid.at(row).at(col) ]
         );
      }
   }
}

Grid::OutOfBounds Grid::checkBounds(const Position& cell) {
   if(cell.col >= m_columns)
      return OutOfBounds::Right;
   else if(cell.row >= m_rows)
      return OutOfBounds::Bottom;
   else if(cell.col < 0)
      return OutOfBounds::Left;
   else
      return OutOfBounds::Inside;
}

bool Grid::isCellEmpty(const Position& cell) {
   if(cell.row == -1 || grid.at(cell.row).at(cell.col) == CellType::Empty)
      return true;
   else return false;
}