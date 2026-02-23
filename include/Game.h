#pragma once
#include <vector>
#include "Blocks.h"
#include "Grid.h"

class Game {
   Grid grid;
   std::vector<Block> blocks{};
   Block currentBlock;
   Block nextBlock;

   /** 7-bag 
    * Tetris uses a 7-bag system. 
    * It generates 7 blocks, uses each till vector is empty, then refills 
    */
   Block getRandomBlock();
   std::vector<Block> resetBlockBag();
   
   void HandleEvents();
   void Draw();
   
   float secondsElapsed = 0.0f; // time elapsed since last tick-event
   bool hasTimeElapsed(float dt, float gravityInterval);
public:
   Game() = default;
   void Init();
   void Run();
};