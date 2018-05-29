#include "GameInstance.h"
#include "Player.h"

namespace BattleShip
{
   GameInstance::GameInstance( int width, int height, GameMode mode ) :
      m_mode( mode ),
      m_width( width ), m_height( height ),
      m_turnCount( 0 ),
      m_attacker( nullptr ), m_defender( nullptr ),
      m_hitMap( nullptr ),
      m_bGameEnd( false )
   {
      m_attacker = new Player( width, height );
      m_defender = new Player( width, height );

      m_hitMap = new HitResultType*[ height ];
      for ( int y = 0; y < m_height; ++y )
      {
         m_hitMap[ y ] = new HitResultType[ m_width ];

         // Initilaize
         for ( int x = 0; x < m_width; ++x )
         {
            m_hitMap[ y ][ x ] = HitResultType::NONE;
         }
      }
   }

   GameInstance::~GameInstance( )
   {
      if ( m_hitMap != nullptr )
      {
         for ( int y = 0; y < m_height; ++y )
         {
            if ( m_hitMap[ y ] != nullptr )
            {
               delete[ ] m_hitMap[ y ];
               m_hitMap[ y ] = nullptr;
            }
         }

         delete[ ] m_hitMap;
         m_hitMap = nullptr;
      }

      SAFE_DELETE( m_defender );
      SAFE_DELETE( m_attacker );
   }
}