#pragma once
#include "Common.h"

namespace BattleShip
{
   class Map;
   class Ship
   {
      friend Map;
   protected:
      Ship( const IntVec2& position, int size );

      IntVec2 GetPosition( ) const { return m_position; }
      bool IsDestroyed( ) const { return ( m_size == m_hitCount ); }

   protected:
      IntVec2 m_position;
      int     m_size;
      int     m_hitCount;

   };
}