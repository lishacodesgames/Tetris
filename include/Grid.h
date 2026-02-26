#pragma once
#include "Colors.h"
#include "Position.h"
#include <raylib.h>
#include <array>

class Grid {
   int m_rows = 20; /// grid height
   int m_columns = 10; /// grid width
   std::array<std::array<CellType, 10>, 20> m_grid{};

   bool m_isRowFull(int row);
   void m_clearRow(int row);

   /** parameters 
    * @param row current row position (which row to move down)
    * @param moveCount how many rows to move down
    */
   void m_moveRowDown(int row, int moveCount);
public:
   int cellSize = 35;
   
   void Clean(); /// clears rows & handles empty ones
   void Draw();

   void Reset(); /// resets grid to CellType::Empty

   /// sets grid[row][col] to block
   void makePermanent(CellType block, int row, int col);

   enum class OutOfBounds { Inside, Right, Bottom, Left , Top };
   OutOfBounds checkBounds(const Position& cell);

   bool isCellEmpty(const Position& cell);
};

inline Grid g_grid;