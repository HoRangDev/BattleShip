// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#include <algorithm>

#include "Ship.h"

namespace BattleShip
{
   Ship::Ship( ShipType type, int size ) :
      m_type( type ),
      m_size( size ),
      m_hitCount( 0 )
   {
      m_positions.reserve( size );
      m_hitPositions.reserve( size );
   }

   bool Ship::operator==( const IntVec2& rhs ) const
   {
      for ( auto pos : m_positions )
      {
         if ( pos == rhs )
         {
            return true;
         }
      }

      return false;
   }

   bool Ship::IsAlreadyHit( const IntVec2& rhs ) const
   {
      for ( auto pos : m_hitPositions )
      {
         if ( pos == rhs )
         {
            return true;
         }
      }

      return false;
   }

   void Ship::IncreaseHitCount( )
   {
      m_hitCount = std::min( m_size, m_hitCount + 1 );
   }
}