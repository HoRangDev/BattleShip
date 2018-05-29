#pragma once
#include "Ship.h"

namespace BattleShip
{
   class BattleShip : public Ship
   {
   public:
      BattleShip( const IntVec2& position ) :
         Ship( position,
               ShipType::BATTLESHIP, 4)
      {
      }

      virtual std::string GetName( ) const override
      {
         return "BattleShip";
      }
   };
}