#pragma once
#include "Colors.h"
#include "Position.h"
#include <unordered_map>
#include <vector>

/// @brief 0deg position = position with most cells in North-East, then 90deg clockwise from there
enum class RotationState {Zero, Ninety, OneEighty, TwoSeventy};

/// @brief each piece will be enveloped in a mini-grid so it can rotate safely
class Block {
   int cellSize;
   RotationState rotation;
protected:
   Position positionOffset; /// each block has its own nxn grid. This attributes tells us the positionOffset of the top-left corner of that grid

   /// @brief moves each cell by given position offset
   std::array<Position, 4> getBlockPosition();
   
public:
   CellType id; /// type of block

   /// @brief tetromino's 4 cells -> occupy which 4 positions 
   std::unordered_map<RotationState, std::array<Position, 4>> cells;

   Block();
   void Move(Position offset);
   void Draw();
};

class Hero : public Block { /// I block, 0 = sleeping, 2nd row of 4x4
public:
   Hero();
};

class Teewee : public Block { /// T block, 0 = upside-down T
public:
   Teewee();
};

class Smashboy : public Block { /// 2x2
public:
   Smashboy();
};

/// @relates Reference/Ricky.jpg 
class Ricky : public Block { /// L block, 0 = sleeping on its back
public:
   Ricky();
};

/// @relates Reference/AutRicky.jpg
class AutRicky : public Block { /// J block, 0 = candy cane
public:
   AutRicky();
};

class Snake : public Block { /// S block, 0 = S in upper part
public:
   Snake();
};

class Znake : public Block { /// Z block, 0 = Z in upper part
public:
   Znake();
};


