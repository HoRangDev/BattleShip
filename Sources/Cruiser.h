#pragma once
#include "Ship.h"

namespace BattleShip
{
   class Cruiser : public Ship
   {
   public:
      Cruiser( const IntVec2& position ) :
         Ship( position,
               ShipType::CRUISER, 3 )
      {
      }

      virtual std::string GetName( ) const override
      {
         return "Cruiser";
      }
   };
}