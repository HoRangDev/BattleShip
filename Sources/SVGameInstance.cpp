#include "SVGameInstance.h"
#include "Player.h"
#include "ShipMap.h"

namespace BattleShip
{
   SVGameInstance::SVGameInstance( int width, int height ) :
      m_defenderMap( nullptr ),
      GameInstance( width, height,
                    GameMode::SUPERVISED )
   {
   }

   void SVGameInstance::Init( )
   {
      m_defenderMap = static_cast< ShipMap* >( m_defender->GetMap( ) );
      m_defenderMap->PlaceRandomly( );
      m_defenderMap->Print( );
   }

   void SVGameInstance::Update( )
   {
      // @TODO: Get Input/Check end condition
   }

   void SVGameInstance::Render( )
   {
      // @TODO: Impl Draw UIs
   }

}