#include <Precompiled.h>
#include <raylib.h>
#include <vector>
#include <random>
#include <ctime>
#include "Game.h"

#include "Blocks.h"
#include "Colors.h"
#include "Grid.h"
#include "Position.h"

void Game::Init() {
   InitWindow(300, 600, "Tetris");
   SetTargetFPS(60);
   srand(time(0));

   blocks = resetBlockBag();
   currentBlock = getRandomBlock();
   nextBlock = getRandomBlock();
}

void Game::Run() {
   while(!WindowShouldClose()) {
      HandleEvents();

      BeginDrawing();
      ClearBackground(ColorBrightness(cellColorMap[CellType::Empty], 0.04f)); // color of the gridlines
      Draw();
      EndDrawing();
   }

   CloseWindow();
}

void Game::HandleEvents() {
   int key = GetKeyPressed();
   switch(key) {
      case KEY_LEFT:
         currentBlock.Move({0, -1});
         break;
      case KEY_RIGHT:
         currentBlock.Move({0, 1});
         break;
      case KEY_DOWN:
         currentBlock.Move({1, 0});
         break;   
      case KEY_SPACE:
         currentBlock.Rotate();
         break;
   }

   if(hasTimeElapsed(GetFrameTime(), 0.35f)) {
      currentBlock.applyGravity();
   }
}

void Game::Draw() {
   grid.Draw();
   currentBlock.Draw();
}

bool Game::hasTimeElapsed(float dt, float gravityInterval) {
   secondsElapsed += dt;

   if(secondsElapsed >= gravityInterval) {
      // not 0 to account for lag. i.e. if lag of 2s, after lag the block will have moved extra 
      // as if the lag never happened
      secondsElapsed -= gravityInterval;
      return true;
   }
   return false;
}

Block Game::getRandomBlock() {
   if(blocks.size() == 0)
      blocks = resetBlockBag();

   int randIndex = rand() % blocks.size();
   Block randomBlock = blocks[randIndex];
   blocks.erase(blocks.begin() + randIndex);
   return randomBlock;
}

std::vector<Block> Game::resetBlockBag() { return {Hero(), Teewee(), Smashboy(), Ricky(), AutRicky(), Snake(), Znake()}; }