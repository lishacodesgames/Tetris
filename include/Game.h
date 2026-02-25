#pragma once
#include <vector>
#include "Blocks.h"

class Game {
   std::vector<Block> blockBag{};
   Block currentBlock;
   Block nextBlock;

   /** 7-bag 
    * Tetris uses a 7-bag system. 
    * It generates 7 blocks, uses each till vector is empty, then refills 
    */
   Block getRandomBlock();
   std::vector<Block> resetBlockBag();
   
   float timeSinceFall = 0.0f; // time elapsed in seconds since last fall
   
   /** parameters 
    * @param dt Time since last frame (explicitly needed bcz lag)
    * @param fallInterval Time between each fall
    */
   bool shouldFall(float dt, float fallInterval);
   
   bool isGameOver = false;
   
   void HandleEvents();
   void Draw();
public:
   Game() = default;
   void Init();
   void Run();
};