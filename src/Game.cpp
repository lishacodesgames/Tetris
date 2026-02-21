#include "Game.h"
#include "Colors.h"
#include <raylib.h>

void Game::Init() {
   InitWindow(300, 600, "Tetris");
   SetTargetFPS(60);
}
void Game::Run() {
   while(!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(ColorBrightness(cellColorMap[CellType::Empty], 0.04f)); // color of the gridlines

      HandleEvents();
      Draw();
      EndDrawing();
   }

   CloseWindow();
}

void Game::HandleEvents() {

}

void Game::Draw() {
   grid.Draw();
   block.Draw();
}