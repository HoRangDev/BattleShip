#pragma once
#include "Vector2.h"

#define SAFE_DELETE(x) { if(x!=nullptr){delete x;} x = nullptr; }

namespace BattleShip
{
   using IntVec2 = Vector2<int>;
   enum class HitResultType
   {
      MISS,
      HIT,
      DESTROY,
      GAME_CLEAR
   };

   enum ShipType
   {
      SHIP_ERROR = -1,
      SHIP_NONE,
      AIRCRAFT,
      BATTLESHIP,
      CRUISER,
      DESTROYER
   };

   enum class GameMode
   {
      SUPERVISED,
      RANDOM,
      OPTIMAL
   };

   enum class BatchAxis
   {
      XAXIS,
      YAXIS,
   };
}