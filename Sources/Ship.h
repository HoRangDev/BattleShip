#pragma once
#include "Common.h"

namespace BattleShip
{
   class Ship
   {
   protected:
      Ship( const IntVec2& position, ShipType type, int size );

   public:
      ShipType GetType( ) const { return m_type; }
      IntVec2 GetPosition( ) const { return m_position; }
      int GetSize( ) const { return m_size; }
      int GetHitCount( ) const { return m_hitCount; }
      bool IsDestroyed( ) const { return ( m_size == m_hitCount ); }

      void IncreaseHitCount( );

      virtual std::string GetName( ) const = 0;

   protected:
      ShipType m_type;
      IntVec2  m_position;
      int      m_size;
      int      m_hitCount;

   };
}