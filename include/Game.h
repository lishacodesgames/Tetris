#pragma once
#include "Blocks.h"
#include "Grid.h"
#include <vector>

class Game {
   Grid grid;
   std::array<Block, 7> blocks{};

   void Draw();
   void HandleEvents();
public:
   Game() = default;
   void Init();
   void Run();
};