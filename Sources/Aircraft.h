// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once

#include "Ship.h"

namespace BattleShip
{
   class Aircraft : public Ship
   {
   public:
      Aircraft( ) :
         Ship( ShipType::AIRCRAFT, 5 )
      {
      }

      virtual std::string GetName( ) const override 
      { 
         return "Aircraft";
      }
   };
}