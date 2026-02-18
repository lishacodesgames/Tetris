#include "Blocks.h"
#include "Colors.h"
#include "Grid.h"

Block::Block() {
   cellSize = 30;
   rotation = RotationState::Zero;
}

void Block::Draw() {
   std::vector<Position> block = this->cells[rotation];

   for(Position& cell : block) {
      DrawRectangle(block[0].col * cellSize + 1, block[0].row * cellSize + 1,
                     cellSize - 1, cellSize - 1, cellColorMap[id]);
   }
}

NormRicky::NormRicky() {
   id = CellState::NormRicky;
   cells[RotationState::Zero] = {{0, 2}, {1, 2}, {1, 1}, {1, 0}};
   cells[RotationState::Ninety] = {{2, 2}, {2, 1}, {1, 1}, {0, 1}};
   cells[RotationState::OneEighty] = {{2, 0}, {1, 0}, {1, 1}, {1, 2}};
   cells[RotationState::TwoSeventy] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
}

AutRicky::AutRicky() {
   id = CellState::AutRicky;
   cells[RotationState::Zero] = {{0, 2}, {0, 1}, {1, 1}, {2, 1}};
   cells[RotationState::Ninety] = {{2, 2}, {1, 2}, {1, 1}, {1, 0}};
   cells[RotationState::OneEighty] = {{2, 0}, {2, 1}, {1, 1}, {0, 1}};
   cells[RotationState::TwoSeventy] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
}

Hero::Hero() {
   
}