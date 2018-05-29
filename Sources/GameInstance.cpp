#include "GameInstance.h"
#include "Player.h"

namespace BattleShip
{
   GameInstance::~GameInstance( )
   {
      SAFE_DELETE( m_attacker );
      SAFE_DELETE( m_defender );
   }
}