#include "RandomGameInstance.h"
#include "Player.h"
#include "ShipMap.h"

namespace BattleShip
{
   RandomGameInstance::RandomGameInstance( int width, int height ) :
      m_defenderMap( nullptr ),
      GameInstance( width, height,
                    GameMode::RANDOM )
   {
   }

   void RandomGameInstance::Init( )
   {
      m_defenderMap = static_cast< ShipMap* >( m_defender->GetMap( ) );
      m_defenderMap->PlaceRandomly( );
      m_defenderMap->Print( );
   }

   void RandomGameInstance::Update( )
   {
      // @TODO: Get Input/Check end condition
   }

   void RandomGameInstance::Render( )
   {
      // @TODO: Impl Draw UIs
   }

}