#include <Precompiled.h>
#include <raylib.h>
#include <vector>
#include "Grid.h"
#include "Colors.h"
#include "Position.h"

#define _DEBUGGING 0

#if _DEBUGGING
#include <cstdio>
#endif

bool Grid::m_isRowFull(int row) {
   for(const CellType& cell : m_grid.at(row)) {
      if(cell == CellType::Empty)
         return false;
   }
   return true;
}

void Grid::m_clearRow(int row) {
   for(CellType& cell : m_grid.at(row)) {
      cell = CellType::Empty;
   }
}

void Grid::m_moveRowDown(int row, int moveCount) {
   int finalRow = row + moveCount;
   if(finalRow < m_rows)
      m_grid[finalRow] = m_grid.at(row);
   m_clearRow(row);
}

void Grid::Clean() {
   int fullRows = 0;

   for(int row = m_rows - 1; row > 0; row--) {
      if(m_isRowFull(row)) {
         m_clearRow(row);
         #if _DEBUGGING
            printf("Clearing row %d\n", row);
         #endif
         fullRows++;
      } else if(fullRows > 0) {
         m_moveRowDown(row, fullRows);
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
            col * cellSize + 3, row * cellSize + 3, 
            cellSize - 3, cellSize - 3, 
            cellColorMap[ m_grid.at(row).at(col) ]
         );
      }
   }
   Rectangle grid = {1.25f, 1.25f, (float)(cellSize * m_columns) - 1.25f, (float)(cellSize * m_rows) - 1.25f};
   DrawRectangleLinesEx(grid, 1.5f, Color{234, 163, 163, 255}); // rgb(234, 163, 163)
}

void Grid::Reset() {
   for(auto& row : m_grid) {
      for(CellType& cell : row) {
         cell = CellType::Empty;
      }
   }
}

void Grid::makePermanent(CellType block, int row, int col) {
   this->m_grid[row][col] = block;
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

   if(m_grid.at(cell.row).at(cell.col) == CellType::Empty)
      return true;
   else return false;
}