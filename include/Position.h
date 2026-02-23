#pragma once
// ik Vector2 exists but for Tetris, {row, col} makes more sense to me than {x, y}

/// a cell's coodinate position in our grid
struct Position {
   int row;
   int col; 

   Position operator+(const Position& other) {
      return {row + other.row, col + other.col};
   }

   Position& operator+=(const Position& other) {
      this->row += other.row;
      this->col += other.col;
      return *this;
   }

   Position& operator-=(const Position& other) {
      this->row -= other.row;
      this->col -= other.col;
      return *this;
   }

   bool operator==(const Position& other) const {
      if(this->row == other.row && this->col == other.col)
         return true;
      else return false;
   }
};