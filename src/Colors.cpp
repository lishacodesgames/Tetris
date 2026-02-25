#include <Precompiled.h>
#include <unordered_map>
#include <raylib.h>
#include "Colors.h"

Color COLOR_GAMEOVER = {210, 255, 40, 255}; // hotpink

static GridColorValues colorValue;
std::unordered_map<CellType, Color> cellColorMap = {
   {CellType::Empty, colorValue.Empty},
   {CellType::Hero, colorValue.Hero},
   {CellType::Teewee, colorValue.Teewee},
   {CellType::Smashboy, colorValue.Smashboy},
   {CellType::Ricky, colorValue.Ricky},
   {CellType::AutRicky, colorValue.AutRicky},
   {CellType::Snake, colorValue.Snake},
   {CellType::Znake, colorValue.Znake}
};