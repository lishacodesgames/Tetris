#include "Colors.h"

static GridColorValues colorValue;

std::map<CellType, Color> cellColorMap = {
   {CellType::Empty, colorValue.Empty},
   {CellType::Hero, colorValue.Hero},
   {CellType::Teewee, colorValue.Teewee},
   {CellType::Smashboy, colorValue.Smashboy},
   {CellType::Ricky, colorValue.Ricky},
   {CellType::AutRicky, colorValue.AutRicky},
   {CellType::Snake, colorValue.Snake},
   {CellType::Znake, colorValue.Znake}
};