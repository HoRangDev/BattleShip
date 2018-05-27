#pragma once

#include "Common.h"

namespace BattleShip
{
   enum class Direction
   {
      Left,
      Right,
      Up,
      Down
   };

   class GameInstance;
   class Ship
   {
   public:
      Ship( GameInstance& inst );

      HitResultType HitCheck( int x, int y );

   protected:
      GameInstance& m_instance;
      int   m_x;
      int   m_y;
      int   m_size;
      int   m_hitCount;
      bool* m_hitCheck;

   };
}