#include <Precompiled.h>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <vector>
#include "Grid.h"
#include "Blocks.h"
#include "Colors.h"
#include "Position.h"

Block::Block() {
   m_cellSize = 30;
   m_rotation = RotationState::Zero;
   p_positionOffset = {0, 3}; // default spawn in the center, overridden by some
}

void Block::Move(Position offset) {
   p_positionOffset += offset;
   m_considerBounds();
}

void Block::Draw() {
   std::array<Position, 4> block = p_getBlockPosition();
   
   for(int i = 0; i < 4; i++) {
      Position& cell = block.at(i);
      DrawRectangle(
         cell.col * m_cellSize + 1, cell.row * m_cellSize + 1,
         m_cellSize - 1, m_cellSize - 1, cellColorMap[id]
      );
   }
}

std::array<Position, 4> Block::p_getBlockPosition() {
   std::array<Position, 4> blockPosition = cells.at(m_rotation);

   for(Position& cell : blockPosition) {
      cell += p_positionOffset;
   }

   return blockPosition;
}

void Block::m_considerBounds() {
   std::array<Position, 4> block = p_getBlockPosition();

   for(const Position& cell : block) {
      if(m_grid.checkBounds(cell) == Grid::OutOfBounds::Top) {
         p_positionOffset += {1, 0}; 
         break;
      }
      else if(m_grid.checkBounds(cell) == Grid::OutOfBounds::Right) {
         p_positionOffset += {0, -1}; 
         break;
      }
      else if(m_grid.checkBounds(cell) == Grid::OutOfBounds::Bottom) {
         p_positionOffset += {-1, 0};
         break;
      }
      else if(m_grid.checkBounds(cell) == Grid::OutOfBounds::Left) {
         p_positionOffset += {0, 1};
         break;
      }
   }
}

/// outer brace: std::array, inner brace: c-array

Hero::Hero() {
   id = CellType::Hero;
   cells[RotationState::Zero] = {{ {1, 0}, {1, 1}, {1, 2}, {1, 3} }};
   cells[RotationState::Ninety] = {{ {0, 2}, {1, 2}, {2, 2}, {3, 2} }};
   cells[RotationState::OneEighty] = {{ {2, 0}, {2, 1}, {2, 2}, {2, 3} }};
   cells[RotationState::TwoSeventy] = {{ {0, 1}, {1, 1}, {2, 1}, {3, 1} }};
   p_positionOffset = {-1, 3};
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
   p_positionOffset = {0, 4};
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
