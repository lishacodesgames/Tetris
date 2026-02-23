#pragma once
#include "Colors.h"
#include "Position.h"
#include <raylib.h>
#include <array>

class Grid {
   int m_rows = 20; /// height
   int m_columns = 10; /// width
public:
   void Draw();
   
   /// all elements initialize to CellType::Empty
   std::array<std::array<CellType, 10>, 20> grid{};
   int cellSize = 30;

   enum class OutOfBounds { Inside, Right, Bottom, Left , Top };
   OutOfBounds checkBounds(const Position& cell);

   bool isCellEmpty(const Position& cell);
};

inline Grid g_grid;