#pragma once
#include "Ship.h"

namespace BattleShip
{
   class BattleShip : public Ship
   {
   public:
      BattleShip( ) :
         Ship( ShipType::BATTLESHIP, 4 )
      {
      }

      virtual std::string GetName( ) const override
      {
         return "BattleShip";
      }
   };
}