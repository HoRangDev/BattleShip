#pragma once
#include "Ship.h"

namespace BattleShip
{
   class Destroyer : public Ship
   {
   public:
      Destroyer( ) :
         Ship( ShipType::DESTROYER, 2 )
      {
      }

      virtual std::string GetName( ) const override
      {
         return "Destroyer";
      }
   };
}