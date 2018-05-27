#pragma once
#define MAXSHIPNUM 5 // 1 Aircraft, 1 Battleship, 1 Cruiser, 2 Destroyer

#include "Common.h"

#include <array>


namespace BattleShip
{
   class Ship;
   class GameInstance;
   using ShipArray = std::array<Ship*, MAXSHIPNUM>;
   class Player
   {
   public:
      Player( GameInstance& inst );
      ~Player( );

      void Init( );

      HitResultType HitCheck( int x, int y );
      const ShipArray& GetShips( ) const { return m_ships; }

   private:
      void RandomShipPlace( );

   protected:
      GameInstance&  m_inst;
      ShipArray      m_ships;

   };
}