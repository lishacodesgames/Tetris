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

#define _DEBUGGING 0

#if _DEBUGGING
#include <cstdio>
#endif

void Game::Init() {
   InitWindow(500, 700, "Tetris");
   SetTargetFPS(40);
   srand(time(0));

   blockBag = resetBlockBag();
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
   while(key != 0) { // processes all keys in queue, 0 = empty
      if(isGameOver) {
         isGameOver = false;
         Reset();
      }
      switch(key) {
         case KEY_LEFT:
            currentBlock.Move({0, -1});
            break;
         case KEY_RIGHT:
            currentBlock.Move({0, 1});
            break;
         case KEY_SPACE:
            currentBlock.Rotate();
            break;
      }
      key = GetKeyPressed();
   }
   if(IsKeyDown(KEY_DOWN)) // VERY fast fall
      currentBlock.Move({1, 0});

   if(shouldFall(GetFrameTime(), 0.35f)) {
      currentBlock.Fall();
   }

   if(currentBlock.isLocked) {
      currentBlock = nextBlock;
      if(currentBlock.isColliding()) {
         isGameOver = true;
         return;
      }
      nextBlock = getRandomBlock();
   }

   g_grid.Clean();
}

void Game::Reset() {
   g_grid.Reset();
   blockBag = resetBlockBag();
   currentBlock = getRandomBlock();
   nextBlock = getRandomBlock();
}

void Game::Draw() {
   g_grid.Draw();
   currentBlock.Draw();

   if(isGameOver) {
      DrawText("Game Over!", 45, GetScreenHeight()/2 - 20, 48, COLOR_GAMEOVER);
      DrawText("Press any key to restart...", 15, GetScreenHeight()/2 + 20, 25, COLOR_GAMEOVER);
   }
}

bool Game::shouldFall(float dt, float fallInterval) {
   timeSinceFall += dt;

   if(timeSinceFall >= fallInterval) {
      timeSinceFall = 0.0f; // not accounting for lag bcz it can mess up gameplay
      return true;
   }
   return false;
}

Block Game::getRandomBlock() {
   if(blockBag.size() == 0)
      blockBag = resetBlockBag();

   int randIndex = rand() % blockBag.size();
   Block randomBlock = blockBag[randIndex];
   blockBag.erase(blockBag.begin() + randIndex);
   return randomBlock;
}

std::vector<Block> Game::resetBlockBag() { 
   return {Hero(), Teewee(), Smashboy(), Ricky(), AutRicky(), Snake(), Znake()}; 
}