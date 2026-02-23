#pragma once
// ik Vector2 exists but for Tetris, {row, col} makes more sense to me than {x, y}

/// a cell's coodinate position in our grid
struct Position {
   int row;
   int col; 

   Position operator+(const Position& other) {
      return {row + other.row, col + other.col};
   }

   /// @return Reference to the original caller 
   Position& operator+=(const Position& other) {
      row += other.row;
      col += other.col;
      return *this;
   }
};