#pragma once
#include "Ship.h"

namespace BattleShip
{
   class Cruiser : public Ship
   {
   public:
      Cruiser( ) :
         Ship( ShipType::CRUISER, 3 )
      {
      }

      virtual std::string GetName( ) const override
      {
         return "Cruiser";
      }
   };
}