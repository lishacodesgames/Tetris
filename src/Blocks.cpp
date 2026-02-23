#include <Precompiled.h>
#include <array>
#include "Blocks.h"

#include "Grid.h"
#include "Colors.h"
#include "Position.h"

Block::RotationState& operator++(Block::RotationState& r) {
   r = static_cast<Block::RotationState>( ( 1 + static_cast<int>(r) ) % 4 ); // % 4 makes it wrap around to 0
   return r;
}

void Block::Move(Position offset) {
   p_positionOffset += offset;
   m_considerBounds();
}

void Block::Rotate() {
   ++m_rotation;
   m_considerBounds();
   if(p_id == CellType::Hero)
      m_considerBounds();
}

void Block::Draw() {
   std::array<Position, 4> block = p_getBlockPosition();
   
   for(int i = 0; i < 4; i++) {
      Position& cell = block.at(i);
      DrawRectangle(
         cell.col * m_grid.cellSize + 1, cell.row * m_grid.cellSize + 1,
         m_grid.cellSize - 1, m_grid.cellSize - 1, cellColorMap[p_id]
      );
   }
}

std::array<Position, 4> Block::p_getBlockPosition() {
   std::array<Position, 4> blockPosition = cells.at(m_rotation); // origin position

   for(Position& cell : blockPosition) {
      cell += p_positionOffset;
   }

   return blockPosition; // current position
}

void Block::m_considerBounds() {
   Grid::OutOfBounds bounds;
   for(const Position& cell : p_getBlockPosition()) {
      bounds = m_grid.checkBounds(cell);

      switch(bounds) {
         case Grid::OutOfBounds::Top:
            p_positionOffset += {1, 0}; 
            break;
         case Grid::OutOfBounds::Right:
            p_positionOffset += {0, -1}; 
            break;
         case Grid::OutOfBounds::Bottom:
            p_positionOffset += {-1, 0};
            break;
         case Grid::OutOfBounds::Left:
            p_positionOffset += {0, 1};
            break;
         case Grid::OutOfBounds::Inside: break; // to avoid warning
      }
   }
}

/// outer brace: std::array, inner brace: c-array

Hero::Hero() {
   p_id = CellType::Hero;
   cells[RotationState::Zero] = {{ {1, 0}, {1, 1}, {1, 2}, {1, 3} }};
   cells[RotationState::Ninety] = {{ {0, 2}, {1, 2}, {2, 2}, {3, 2} }};
   cells[RotationState::OneEighty] = {{ {2, 0}, {2, 1}, {2, 2}, {2, 3} }};
   cells[RotationState::TwoSeventy] = {{ {0, 1}, {1, 1}, {2, 1}, {3, 1} }};
   p_positionOffset = {-1, 3};
}

Teewee::Teewee() {
   p_id = CellType::Teewee;
   cells[RotationState::Zero] = {{ {1, 0}, {1, 1}, {1, 2}, {0, 1} }};
   cells[RotationState::Ninety] = {{ {0, 1}, {1, 1}, {2, 1}, {1, 2} }};
   cells[RotationState::OneEighty] = {{ {1, 0}, {1, 1}, {1, 2}, {2, 1} }};
   cells[RotationState::TwoSeventy] = {{ {0, 1}, {1, 1}, {2, 1}, {1, 0} }};
}

Smashboy::Smashboy() {
   p_id = CellType::Smashboy;
   cells[RotationState::Zero] = {{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }};
   p_positionOffset = {0, 4};
}

Ricky::Ricky() {
   p_id = CellType::Ricky;
   cells[RotationState::Zero] = {{ {0, 2}, {1, 2}, {1, 1}, {1, 0}} }; 
   cells[RotationState::Ninety] = {{ {2, 2}, {2, 1}, {1, 1}, {0, 1} }};
   cells[RotationState::OneEighty] = {{ {2, 0}, {1, 0}, {1, 1}, {1, 2} }};
   cells[RotationState::TwoSeventy] = {{ {0, 0}, {0, 1}, {1, 1}, {2, 1} }};
}

AutRicky::AutRicky() {
   p_id = CellType::AutRicky;
   cells[RotationState::Zero] = {{ {0, 0}, {1, 0}, {1, 1}, {1, 2} }};
   cells[RotationState::Ninety] = {{ {0, 2}, {0, 1}, {1, 1}, {2, 1} }};
   cells[RotationState::OneEighty] = {{ {2, 2}, {1, 2}, {1, 1}, {1, 0} }};
   cells[RotationState::TwoSeventy] = {{ {2, 0}, {2, 1}, {1, 1}, {0, 1} }};
}

Snake::Snake() {
   p_id = CellType::Snake;
   cells[RotationState::Zero] = {{ {1, 0}, {1, 1}, {0, 1}, {0, 2} }};
   cells[RotationState::Ninety] = {{ {0, 1}, {1, 1}, {1, 2}, {2, 2} }};
   cells[RotationState::OneEighty] = {{ {2, 0}, {2, 1}, {1, 1}, {1, 2} }};
   cells[RotationState::TwoSeventy] = {{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }};
}

Znake::Znake() {
   p_id = CellType::Znake;
   cells[RotationState::Zero] = {{ {0, 0}, {0, 1}, {1, 1}, {1, 2} }};
   cells[RotationState::Ninety] = {{ {0, 2}, {1, 2}, {1, 1}, {2, 1} }};
   cells[RotationState::OneEighty] = {{ {1, 0}, {1, 1}, {2, 1}, {2, 2} }};
   cells[RotationState::TwoSeventy] = {{ {0, 1}, {1, 1}, {1, 0}, {2, 0} }};
}
