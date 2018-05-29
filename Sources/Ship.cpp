#include <algorithm>

#include "Ship.h"

namespace BattleShip
{
   Ship::Ship( const IntVec2& position, ShipType type, int size ) :
      m_position( position ),
      m_type( type ),
      m_size( size ),
      m_hitCount( 0 )
   {
   }

   void Ship::IncreaseHitCount( )
   {
      m_hitCount = std::min( m_size, m_hitCount + 1 );
   }
}