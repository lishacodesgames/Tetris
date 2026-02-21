#include "Game.h"
#include "Resources.h"
#include <raylib.h>

void Game::Init() {
   Window window(300, 600, "Tetris");
   SetTargetFPS(60);
}
void Game::Run() {
   while(!WindowShouldClose()) {
      Drawing draw;
      ClearBackground(ColorBrightness(cellColorMap[CellType::Empty], 0.04f)); // color of the gridlines

      HandleEvents();
      Draw();
   }
}

void Game::HandleEvents() {
   
}

void Game::Draw() {
   grid.Draw();
   Lblock.Draw();
}