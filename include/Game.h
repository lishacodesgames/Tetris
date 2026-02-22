#pragma once
#include "Blocks.h"
#include "Grid.h"
#include <vector>

class Game {
   Grid grid;
   std::vector<Block> blocks{};
   
   Block currentBlock;
   Block nextBlock;

   /// @brief Tetris uses a 7-bag system. It generates 7 blocks, uses each till vector is empty, then refills
   Block getRandomBlock();
   std::vector<Block> resetBlockBag();
   
   void HandleEvents();
   void Draw();
public:
   Game() = default;
   void Init();
   void Run();
};