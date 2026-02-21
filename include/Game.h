#pragma once
#include "Blocks.h"
#include "Grid.h"

class Game {
   Grid grid;
   Znake block;

   void Draw();
   void HandleEvents();
public:
   Game() = default;
   void Init();
   void Run();
};