#include "Blocks.h"
#include "Colors.h"

Block::Block() {
   cellSize = 30;
   rotation = RotationState::Zero;
}

void Block::Draw() {
   std::array<Position, 4> block = this->cells[rotation];

   for(const Position& cell : block) {
      DrawRectangle(
         cell.col * cellSize + 1, cell.row * cellSize + 1,
         cellSize - 1, cellSize - 1, cellColorMap[id]
      );
   }
}

/// outer brance: std::array, inner brace: c-array

Hero::Hero() {
   id = CellType::Hero;
   cells.at(RotationState::Zero) = {{ {1, 0}, {1, 1}, {1, 2}, {1, 3} }};
   cells.at(RotationState::Ninety) = {{ {0, 2}, {1, 2}, {2, 2}, {3, 2} }};
   cells.at(RotationState::OneEighty) = {{ {2, 0}, {2, 1}, {2, 2}, {2, 3} }};
   cells.at(RotationState::TwoSeventy) = {{ {0, 1}, {1, 1}, {2, 1}, {3, 1} }};
}

Teewee::Teewee() {
   id = CellType::Teewee;
   cells.at(RotationState::Zero) = {{ {1, 0}, {1, 1}, {1, 2}, {0, 1} }};
   cells.at(RotationState::Ninety) = {{ {0, 1}, {1, 1}, {2, 1}, {1, 2} }};
   cells.at(RotationState::OneEighty) = {{ {1, 0}, {1, 1}, {1, 2}, {2, 1} }};
   cells.at(RotationState::TwoSeventy) = {{ {0, 1}, {1, 1}, {2, 1}, {1, 0} }};
}

Smashboy::Smashboy() {
   id == CellType::Smashboy;
   cells.at(RotationState::Zero) = {{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }};
   cells.at(RotationState::Ninety) = {{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }};
   cells.at(RotationState::OneEighty) = {{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }};
   cells.at(RotationState::TwoSeventy) = {{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }};
}

Ricky::Ricky() {
   id = CellType::Ricky;
   cells.at(RotationState::Zero) = {{ {0, 2}, {1, 2}, {1, 1}, {1, 0}} }; 
   cells.at(RotationState::Ninety) = {{ {2, 2}, {2, 1}, {1, 1}, {0, 1} }};
   cells.at(RotationState::OneEighty) = {{ {2, 0}, {1, 0}, {1, 1}, {1, 2} }};
   cells.at(RotationState::TwoSeventy) = {{ {0, 0}, {0, 1}, {1, 1}, {2, 1} }};
}

AutRicky::AutRicky() {
   id = CellType::AutRicky;
   cells.at(RotationState::Zero) = {{ {0, 0}, {1, 0}, {1, 1}, {1, 2} }};
   cells.at(RotationState::Ninety) = {{ {0, 2}, {0, 1}, {1, 1}, {2, 1} }};
   cells.at(RotationState::OneEighty) = {{ {2, 2}, {1, 2}, {1, 1}, {1, 0} }};
   cells.at(RotationState::TwoSeventy) = {{ {2, 0}, {2, 1}, {1, 1}, {0, 1} }};
}

Snake::Snake() {
   id = CellType::Snake;
   cells.at(RotationState::Zero) = {{ {1, 0}, {1, 1}, {0, 1}, {0, 2} }};
   cells.at(RotationState::Ninety) = {{ {0, 1}, {1, 1}, {1, 2}, {2, 2} }};
   cells.at(RotationState::OneEighty) = {{ {2, 0}, {2, 1}, {1, 1}, {1, 2} }};
   cells.at(RotationState::TwoSeventy) = {{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }};
}

Znake::Znake() {
   id = CellType::Znake;
   cells.at(RotationState::Zero) = {{ {0, 0}, {0, 1}, {1, 1}, {1, 2} }};
   cells.at(RotationState::Ninety) = {{ {0, 2}, {1, 2}, {1, 1}, {2, 1} }};
   cells.at(RotationState::OneEighty) = {{ {1, 0}, {1, 1}, {2, 1}, {2, 2} }};
   cells.at(RotationState::TwoSeventy) = {{ {0, 1}, {1, 1}, {1, 0}, {2, 0} }};
}
