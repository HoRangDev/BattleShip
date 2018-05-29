#pragma once

#include "Ship.h"

namespace BattleShip
{
   class Aircraft : public Ship
   {
   public:
      Aircraft( const IntVec2& position ) :
         Ship( position,
               ShipType::AIRCRAFT, 5)
      {
      }

      virtual std::string GetName( ) const override 
      { 
         return "Aircraft";
      }
   };
}