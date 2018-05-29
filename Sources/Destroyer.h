#pragma once
#include "Ship.h"

namespace BattleShip
{
   class Destroyer : public Ship
   {
   public:
      Destroyer( const IntVec2& position ) :
         Ship( position,
               ShipType::DESTROYER, 1)
      {
      }

      virtual std::string GetName( ) const override
      {
         return "Destroyer";
      }
   };
}