#include "Colors.h"

static GridColorValues colorValue;

std::map<CellState, Color> cellColorMap = {
   {CellState::Empty, colorValue.Empty},
   {CellState::Hero, colorValue.Hero},
   {CellState::Teewee, colorValue.Teewee},
   {CellState::Smashboy, colorValue.Smashboy},
   {CellState::NormRicky, colorValue.NormRicky},
   {CellState::AutRicky, colorValue.AutRicky},
   {CellState::Snake, colorValue.Snake},
   {CellState::Znake, colorValue.Znake}
};