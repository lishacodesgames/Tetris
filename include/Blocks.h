#pragma once
#include "Colors.h"
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

/// @relates Reference/NormRicky.jpg 
class NormRicky : public Block { /// L block, 0 = sleeping on its back
public:
   NormRicky();
};

class AutRicky : public Block { /// J block, 0 = candy cane
public:
   AutRicky();
};

class Hero : public Block { // I block, 0 = 2nd col of 4x4
public:
   Hero();
};