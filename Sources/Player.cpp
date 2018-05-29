#include "Player.h"
#include "ShipMap.h"
#include "HitMap.h"

namespace BattleShip
{
   Player::Player( int width, int height, PlayerType type ) :
      m_type( type ),
      m_map( nullptr )
   {
      switch ( type )
      {
      case PlayerType::ATTACKER:
         m_map = new HitMap( width, height );
         break;

      case PlayerType::DEFENDER:
         m_map = new ShipMap( width, height );
         break;
      }
   }

   Player::~Player( )
   {
      SAFE_DELETE( m_map );
   }

   HitResult Player::HitCheck( const IntVec2& pos )
   {
      HitResult hitRes{ HitResultType::MISS, ShipType::SHIP_ERROR };
      if ( m_type == PlayerType::DEFENDER )
      {
         ShipMap* map = static_cast< ShipMap* >( m_map );
         if ( map != nullptr )
         {
            hitRes = map->HitCheck( pos );
         }
      }

      return hitRes;
   }

   bool Player::AllDestroyed( ) const
   {
      if ( m_map == nullptr ||
           m_type == PlayerType::ATTACKER )
      {
         return false;
      }

      ShipMap* map = static_cast< ShipMap* >( m_map );
      return map->AllDestroyed( );
   }

}