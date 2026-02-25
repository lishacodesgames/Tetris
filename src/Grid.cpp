#include <Precompiled.h>
#include <raylib.h>
#include <cstdio>
#include <vector>
#include "Grid.h"
#include "Colors.h"
#include "Position.h"

#define _DEBUGGING 0

bool Grid::isRowFull(int row) {
   for(const CellType& cell : grid.at(row)) {
      if(cell == CellType::Empty)
         return false;
   }
   return true;
}

void Grid::clearRow(int row) {
   for(CellType& cell : grid.at(row)) {
      cell = CellType::Empty;
   }
}

void Grid::moveRowDown(int row, int moveCount) {
   int finalRow = row + moveCount;
   if(finalRow < m_rows)
      grid[finalRow] = grid.at(row);
   clearRow(row);
}

void Grid::Clean() {
   int fullRows = 0;

   for(int row = m_rows - 1; row > 0; row--) {
      if(isRowFull(row)) {
         clearRow(row);
         #if _DEBUGGING
            printf("Clearing row %d\n", row);
         #endif
         fullRows++;
      } else if(fullRows > 0) {
         moveRowDown(row, fullRows);
         #if _DEBUGGING
            printf("Moving row %d down by %d\n", row-1, fullRows);
         #endif         
      }
   }
}

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
   if(cell.row == -1)
      return true;

   if(grid.at(cell.row).at(cell.col) == CellType::Empty)
      return true;
   else return false;
}