#pragma once
#include "Grid.h"
#include <map>
#include <vector>

/// @brief 0deg position = position with most cells in North-East, then 90deg clockwise from there
enum class RotationState {Zero, Ninety, OneEighty, TwoSeventy};

/// @brief each piece will be enveloped in a mini-grid so it can rotate safely
class Block {
   int cellSize;
   RotationState rotation;
public:
   /// @brief type of block
   CellState id;

   /// @brief tetromino's 4 cells -> occupy which 4 positions 
   std::map<RotationState, std::vector<Position>> cells;

   Block();
   void Draw();
};