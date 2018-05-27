#pragma once

enum class HitResultType
{
   MISS,
   HIT,
   DESTROY,
   GAME_CLEAR
};

enum class ShipType
{
   SHIP_NONE,
   AIRCRAFT,
   BATTLESHIP,
   CRUISER,
   DESTROYER,
   SHIP_CANT_PLACE
};

enum class GameMode
{
   SUPERVISED,
   RANDOM,
   OPTIMAL
};

#define SAFE_DELETE(x) { if(x!=nullptr){delete x;} x = nullptr; }