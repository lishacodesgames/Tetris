#pragma once
#include "Colors.h"
#include "Position.h"
#include <unordered_map>
#include <vector>

/// each piece will be enveloped in a mini-grid so it can rotate safely
class Block {
protected: 
// -------------- PROTECTED --------------

   /** offset of block's origin
    * @details each block has its own nxn grid. 
    * This attributes tells us the positionOffset of the top-left corner of that grid
    */
   Position p_positionOffset; 

   /// Moves each cell by given position offset
   std::array<Position, 4> p_getBlockPosition();
   
public:
// -------------- PUBLIC --------------

   /// 0deg position = position with most cells in North-East, then 90deg clockwise from there
   enum class RotationState {Zero, Ninety, OneEighty, TwoSeventy};

   CellType id; /// type of block

   /// Tetromino's 4 cells -> occupy which 4 positions 
   std::unordered_map<RotationState, std::array<Position, 4>> cells;

   Block();
   void Move(Position offset);
   void Draw();

private:
   int m_cellSize;
   RotationState m_rotation;
};

// -------------- CHILDREN BLOCKS --------------

/** I block, 0 = sleeping, 2nd row of 4x4
 * \see Reference/Hero.jpg
*/
class Hero : public Block { 
public:
   Hero();
};

/** T block, 0 = upside-down T
 * \see Reference\Teewee.jpg
*/
class Teewee : public Block {
public:
   Teewee();
};

/** 2x2, only valid rotation = 0
 * \see Reference\Smashboy.jpg
 */
class Smashboy : public Block {
public:
   Smashboy();
};

/** L block, 0 = sleeping on its back
 * \see Reference/Ricky.jpg
*/ 
class Ricky : public Block {
public:
   Ricky();
};

   /** J block, 0 = candy cane
   * \see Reference/AutRicky.jpg
   */
class AutRicky : public Block {
public:
   AutRicky();
};

/** S block, 0 = S in upper part
 * \see Reference/Snake.jpg
 */
class Snake : public Block {
public:
   Snake();
};

/** Z block, 0 = Z in upper part
 * \see Reference/Znake.jpg
 */
class Znake : public Block {
public:
   Znake();
};


