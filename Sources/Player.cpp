#include "Player.h"
#include "Map.h"

namespace BattleShip
{
   Player::Player( int width, int height ) :
      m_map( new Map( width, height ) )
   {
   }

   Player::~Player( )
   {
      SAFE_DELETE( m_map );
   }

   HitResult Player::HitCheck( const IntVec2& pos )
   {
      HitResult hitRes{ HitResultType::MISS, ShipType::SHIP_ERROR };
      if ( m_map != nullptr )
      {
         hitRes = m_map->HitCheck( pos );
      }

      return hitRes;
   }

}