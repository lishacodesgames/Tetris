#pragma once

/// a cell's coodinate position rin our grid
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