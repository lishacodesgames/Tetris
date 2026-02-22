#include <Precompiled.h>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <vector>
#include "Blocks.h"
#include "Colors.h"
#include "Position.h"

Block::Block() {
   cellSize = 30;
   rotation = RotationState::Zero;
   positionOffset = {0, 3}; // default spawn in the center, overridden but some
}

std::array<Position, 4> Block::getBlockPosition() {
   std::array<Position, 4> blockPosition = cells.at(rotation);
   std::vector<Position> movedPositions{};

   for(Position& currentCellPosition : blockPosition) {
      movedPositions.push_back(currentCellPosition + positionOffset);
   }

   std::array<Position, 4> finalBlockPosition{};
   std::copy(movedPositions.begin(), movedPositions.end(), finalBlockPosition.begin());

   return finalBlockPosition;
}

void Block::Move(Position offset) {
   positionOffset = offset;
}

void Block::Draw() {
   std::array<Position, 4> block = getBlockPosition();

   for(int i = 0; i < 4; i++) {
      Position& cell = block.at(i);
      DrawRectangle(
         cell.col * cellSize + 1, cell.row * cellSize + 1,
         cellSize - 1, cellSize - 1, cellColorMap[id]
      );
   }
}

/// outer brance: std::array, inner brace: c-array

Hero::Hero() {
   id = CellType::Hero;
   cells[RotationState::Zero] = {{ {1, 0}, {1, 1}, {1, 2}, {1, 3} }};
   cells[RotationState::Ninety] = {{ {0, 2}, {1, 2}, {2, 2}, {3, 2} }};
   cells[RotationState::OneEighty] = {{ {2, 0}, {2, 1}, {2, 2}, {2, 3} }};
   cells[RotationState::TwoSeventy] = {{ {0, 1}, {1, 1}, {2, 1}, {3, 1} }};
   positionOffset = {-1, 3};
}

Teewee::Teewee() {
   id = CellType::Teewee;
   cells[RotationState::Zero] = {{ {1, 0}, {1, 1}, {1, 2}, {0, 1} }};
   cells[RotationState::Ninety] = {{ {0, 1}, {1, 1}, {2, 1}, {1, 2} }};
   cells[RotationState::OneEighty] = {{ {1, 0}, {1, 1}, {1, 2}, {2, 1} }};
   cells[RotationState::TwoSeventy] = {{ {0, 1}, {1, 1}, {2, 1}, {1, 0} }};
}

Smashboy::Smashboy() {
   id = CellType::Smashboy;
   cells[RotationState::Zero] = {{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }};
   positionOffset = {0, 4};
}

Ricky::Ricky() {
   id = CellType::Ricky;
   cells[RotationState::Zero] = {{ {0, 2}, {1, 2}, {1, 1}, {1, 0}} }; 
   cells[RotationState::Ninety] = {{ {2, 2}, {2, 1}, {1, 1}, {0, 1} }};
   cells[RotationState::OneEighty] = {{ {2, 0}, {1, 0}, {1, 1}, {1, 2} }};
   cells[RotationState::TwoSeventy] = {{ {0, 0}, {0, 1}, {1, 1}, {2, 1} }};
}

AutRicky::AutRicky() {
   id = CellType::AutRicky;
   cells[RotationState::Zero] = {{ {0, 0}, {1, 0}, {1, 1}, {1, 2} }};
   cells[RotationState::Ninety] = {{ {0, 2}, {0, 1}, {1, 1}, {2, 1} }};
   cells[RotationState::OneEighty] = {{ {2, 2}, {1, 2}, {1, 1}, {1, 0} }};
   cells[RotationState::TwoSeventy] = {{ {2, 0}, {2, 1}, {1, 1}, {0, 1} }};
}

Snake::Snake() {
   id = CellType::Snake;
   cells[RotationState::Zero] = {{ {1, 0}, {1, 1}, {0, 1}, {0, 2} }};
   cells[RotationState::Ninety] = {{ {0, 1}, {1, 1}, {1, 2}, {2, 2} }};
   cells[RotationState::OneEighty] = {{ {2, 0}, {2, 1}, {1, 1}, {1, 2} }};
   cells[RotationState::TwoSeventy] = {{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }};
}

Znake::Znake() {
   id = CellType::Znake;
   cells[RotationState::Zero] = {{ {0, 0}, {0, 1}, {1, 1}, {1, 2} }};
   cells[RotationState::Ninety] = {{ {0, 2}, {1, 2}, {1, 1}, {2, 1} }};
   cells[RotationState::OneEighty] = {{ {1, 0}, {1, 1}, {2, 1}, {2, 2} }};
   cells[RotationState::TwoSeventy] = {{ {0, 1}, {1, 1}, {1, 0}, {2, 0} }};
}
