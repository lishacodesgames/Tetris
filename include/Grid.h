#pragma once
#include "Colors.h"
#include <raylib.h>
#include <array>
#include <map>

class Grid {
   int rows, columns;
   int cellSize;
   GridColorValues colorValue;
public:
   std::array<std::array<CellType, 10>, 20> grid{};

   Grid();
   void Draw();
};

/// @brief a cell's coodinate position rin our grid
struct Position { int row, col; };