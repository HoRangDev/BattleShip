#include "SVGameInstance.h"
#include "Player.h"
#include "HitMap.h"
#include "ShipMap.h"
#include "MapUI.h"
#include "StatUI.h"

namespace BattleShip
{
   SVGameInstance::SVGameInstance( int width, int height ) :
      m_defenderMap( nullptr ),
      m_attackerMapUI( nullptr ),
      m_defenderMapUI( nullptr ),
      m_statUI( nullptr ),
      GameInstance( width, height,
                    GameMode::SUPERVISED )
   {
   }

   void SVGameInstance::Init( )
   {
      auto attackerMap = static_cast< HitMap* >( m_attacker->GetMap( ) );
      m_defenderMap = static_cast< ShipMap* >( m_defender->GetMap( ) );
      m_defenderMap->PlaceRandomly( );

      m_defenderMapUI = new MapUI(
         "Defender",
         IntVec2{ 1, 2 },
         22, 12,
         m_defenderMap );
      m_defenderMapUI->SetSpace( IntVec2{ 1, 0 } );

      m_attackerMapUI = new MapUI(
         "Attacker",
         IntVec2{ 1, 14 },
         22, 12,
         attackerMap );
      m_attackerMapUI->SetSpace( IntVec2{ 1, 0 } );

      m_statUI = new StatUI( "< Status >",
                             IntVec2{ 26, 2 },
                             20, 9, 
                             m_defenderMap->GetShipList( ) );
   }

   void SVGameInstance::Update( )
   {
      // @TODO: Get Input/Check end condition
      if ( m_statUI != nullptr )
      {
         m_statUI->SetTurn( GetTurnCount( ) );
      }
   }

   void SVGameInstance::Render( )
   {
      // @TODO: Impl Draw UIs
      if ( m_attackerMapUI != nullptr )
      {
         m_attackerMapUI->Draw( );
      }

      if ( m_defenderMap != nullptr )
      {
         m_defenderMapUI->Draw( );
      }

      if ( m_statUI != nullptr )
      {
         m_statUI->Draw( );
      }
   }

}