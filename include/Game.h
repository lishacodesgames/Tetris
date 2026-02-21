#pragma once
#include "Blocks.h"
#include "Grid.h"

class Game {
   Grid grid;
   Ricky Lblock;

   void Draw();
   void HandleEvents();
public:
   Game() = default;
   void Init();
   void Run();
};