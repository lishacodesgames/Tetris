#pragma once
#include <raylib.h>
#include <map>

enum class CellState {
   Empty,
   Hero, // I
   Teewee, // T
   Smashboy, // 2x2
   NormRicky, // normal L
   AutRicky, // backwards L (autistic Ricky)
   Snake, // S
   Znake //Z
};
struct GridColorValues {
   Color Empty = {30, 30, 46, 255}; // rgb(30, 30, 46)
   Color Hero = {0, 200, 215, 255}; // I -- rgb(0, 200, 215)
   Color Teewee = {155, 93, 229, 255}; // T -- rgb(155, 93, 229)
   Color Smashboy = {242, 201, 76, 255}; // 2x2 -- rgb(242, 201, 76)
   Color NormRicky = {242, 153, 74, 255}; // normal L -- rgb(242, 153, 74)
   Color AutRicky = {47, 128, 237, 255}; // backwards L (autistic Ricky) -- rgb(47, 128, 237)
   Color Snake = {39, 174, 96, 255}; // S -- rgb(39, 174, 96)
   Color Znake = {235, 87, 87, 255}; //Z -- rgb(235, 87, 87)
};

std::map<CellState, Color> cellColorMap;