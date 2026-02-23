#include <Precompiled.h>
#include <raylib.h>
#include <vector>
#include <random>
#include <ctime>
#include "Game.h"
#include "Colors.h"
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
   nextBlock.Move({11, 4});
}

void Game::Draw() {
   grid.Draw();
   currentBlock.Draw();
   nextBlock.Draw();
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