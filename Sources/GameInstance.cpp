#include "GameInstance.h"
#include "Player.h"

namespace BattleShip
{
   GameInstance::GameInstance( int width, int height, GameMode mode ) :
      m_mode( mode ),
      m_width( width ), m_height( height ),
      m_turnCount( 0 ),
      m_attacker( nullptr ), m_defender( nullptr ),
      m_bGameEnd( false )
   {
      m_attacker = new Player( width, height );
      m_defender = new Player( width, height );
   }

   GameInstance::~GameInstance( )
   {
      SAFE_DELETE( m_attacker );
      SAFE_DELETE( m_defender );
   }
}