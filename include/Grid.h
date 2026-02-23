#pragma once
#include "Colors.h"
#include <raylib.h>
#include <array>
#include <map>

class Grid {
   int m_rows, m_columns;
   int m_cellSize;
public:
   /// rows = 20, columns = 10
   std::array<std::array<CellType, 10>, 20> grid{};

   Grid();
   void Draw();
};