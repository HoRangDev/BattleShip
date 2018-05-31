#pragma once
#include "Vector2.h"

#include <string>
#include <random>
#include <cstdlib>
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

   static std::string ShipTypeToName( ShipType type )
   {
      switch ( type )
      {
      case ShipType::DESTROYER:
         return "Destroyer";

      case ShipType::AIRCRAFT:
         return "Aircraft";

      case ShipType::BATTLESHIP:
         return "BattleShip";

      case ShipType::CRUISER:
         return "Cruiser";

      case ShipType::SHIP_NONE:
         return "None";
      }

      return "Error";
   }

   /* Range: [0, 10] => [A, K]**/
   static char NaturalNumberToAlpha( int number )
   {
      switch ( number )
      {
      case 0:
         return 'A';
      case 1:
         return 'B';
      case 2:
         return 'C';
      case 3:
         return 'D';
      case 4:
         return 'E';
      case 5:
         return 'F';
      case 6:
         return 'G';
      case 7:
         return 'H';
      case 8:
         return 'I';
      case 9:
         return 'J';
      case 10:
         return 'K';
      default:
         return 'L';
      }
   }

   /* Range: [A(a), K(k)] => [0, 10]**/
   static int AlphaToNaturalNumber( char alpha )
   {
      switch ( alpha )
      {
      case 'A':
      case 'a':
         return 0;

      case 'B':
      case 'b':
         return 1;

      case 'C':
      case 'c':
         return 2;

      case 'D':
      case 'd':
         return 3;

      case 'E':
      case 'e':
         return 4;

      case 'F':
      case 'f':
         return 5;

      case 'G':
      case 'g':
         return 6;

      case 'H':
      case 'h':
         return 7;

      case 'I':
      case 'i':
         return 8;

      case 'J':
      case 'j':
         return 9;

      case 'K':
      case 'k':
         return 10;

      default:
         return -1;
      }
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

   static std::string HitResultToString( HitResult res )
   {
      std::string result;
      switch ( res.type )
      {
      case HitResultType::DESTROY:
         result = ShipTypeToName( res.ship ) + " Destroyed!";
         break;

      case HitResultType::HIT:
         result = "Hit!";
         break;

      case HitResultType::MISS:
         result = "Miss..";
         break;
      }

      return result;
   }
}