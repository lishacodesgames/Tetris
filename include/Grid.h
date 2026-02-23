#pragma once
#include "Colors.h"
#include "Position.h"
#include <raylib.h>
#include <array>

class Grid {
   int m_rows, m_columns;
   int m_cellSize;
public:
   /// rows = 20, columns = 10
   std::array<std::array<CellType, 10>, 20> grid{};

   enum class OutOfBounds { Inside, Top, Right, Bottom, Left };
   OutOfBounds checkBounds(const Position& cell);

   Grid();
   void Draw();
};