#pragma once
#include "Vector2.h"

#include <string>
#include <random>
#include <curses.h>

#define SAFE_DELETE(x) { if(x!=nullptr){delete x;} x = nullptr; }

namespace BattleShip
{
   using IntVec2 = Vector2<int>;
   enum class PlayerType
   {
      ATTACKER,
      DEFENDER
   };

   enum ColorSet
   {
      WHITEBLACK = 1,
      GREENBLACK,
      REDBLACK,
      YELLOWBLACK,
      WHITEGREEN,
      BLACKYELLOW,
      BLACKCYAN,
      REDWHITE,
      WHITERED,
      MAGENTAWHITE,
      WHITEMAGENTA,
   };

   enum HitResultType
   {
      NONE = -1,
      MISS,
      HIT,
      DESTROY
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

   static char HitResultTypeToChar( HitResultType type )
   {
      switch ( type )
      {
      case HitResultType::HIT:
      case HitResultType::DESTROY:
         return '*';

      case HitResultType::MISS:
         return 'X';

      case HitResultType::NONE:
         return '.';
      }

      return 'E';
   }

   static char ShipTypeToChar( ShipType type )
   {
      switch ( type )
      {
      case ShipType::DESTROYER:
         return 'D';
         
      case ShipType::AIRCRAFT:
         return 'A';

      case ShipType::BATTLESHIP:
         return 'B';

      case ShipType::CRUISER:
         return 'C';

      case ShipType::SHIP_NONE:
         return '.';
      }

      return '-';
   }

   static int GenRandInt( int min, int max )
   {
      std::random_device rd;
      std::mt19937 gen( rd( ) );
      std::uniform_int_distribution<> dis( min, max );

      return dis( gen );
   }

   struct HitResult
   {
      HitResultType type;
      ShipType      ship;
   };
}