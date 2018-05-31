// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once
#include "Common.h"

namespace BattleShip
{
   class Ship
   {
   protected:
      Ship( ShipType type, int size );

   public:
      bool operator==( const IntVec2& rhs ) const;

      ShipType GetType( ) const { return m_type; }

      void AddPosition( const IntVec2& pos ) { m_positions.push_back( pos ); }
      std::vector<IntVec2> GetPositions( ) const { return m_positions; }

      void AddHitPosition( const IntVec2& pos ) { m_hitPositions.push_back( pos ); }
      bool IsAlreadyHit( const IntVec2& pos ) const;

      int GetSize( ) const { return m_size; }
      int GetHitCount( ) const { return m_hitCount; }
      bool IsDestroyed( ) const { return ( m_size == m_hitCount ); }
      void IncreaseHitCount( );

      virtual std::string GetName( ) const = 0;

      // @TODO: Add Reset

   protected:
      ShipType m_type;
      std::vector<IntVec2> m_positions;
      std::vector<IntVec2> m_hitPositions;
      int      m_size;
      int      m_hitCount;

   };
}