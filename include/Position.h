#pragma once

/// @brief a cell's coodinate position rin our grid
struct Position { 
   int row;
   int col; 

   Position operator+(const Position& other) {
      return {row + other.row, col + other.col};
   }
};