#pragma once
#include "Colors.h"
#include "Position.h"
#include <raylib.h>
#include <array>

class Grid {
   int m_rows = 20; /// grid height
   int m_columns = 10; /// grid width

   bool isRowFull(int row);
   void clearRow(int row);

   /// @param row current row position (which row to move down)
   /// @param moveCount how many rows to move down
   void moveRowDown(int row, int moveCount);
public:
   void Clean(); /// clears rows & handles empty ones
   void Draw();
   
   std::array<std::array<CellType, 10>, 20> grid{};
   int cellSize = 30;

   enum class OutOfBounds { Inside, Right, Bottom, Left , Top };
   OutOfBounds checkBounds(const Position& cell);

   bool isCellEmpty(const Position& cell);
};

inline Grid g_grid;