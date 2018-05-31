#include "SVGameInstance.h"
#include "Player.h"
#include "HitMap.h"
#include "ShipMap.h"
#include "MapUI.h"
#include "StatUI.h"
#include "InputUI.h"

namespace BattleShip
{
   SVGameInstance::SVGameInstance( int width, int height ) :
      m_defenderMap( nullptr ),
      m_attackerMapUI( nullptr ),
      m_defenderMapUI( nullptr ),
      m_statUI( nullptr ),
      m_inputUI( nullptr ),
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
         IntVec2{ 3, 2 },
         m_width * 3 + 2, m_height + 2,
         m_defenderMap );
      m_defenderMapUI->SetSpace( IntVec2{ 2, 0 } );

      m_attackerMapUI = new MapUI(
         "Attacker",
         IntVec2{ 3, 6 + m_height },
         m_width * 3 + 2, m_height + 2,
         attackerMap );
      m_attackerMapUI->SetSpace( IntVec2{ 2, 0 } );

      m_statUI = new StatUI( "< Status >",
                             IntVec2{ m_width * 3 + 6, 2 },
                             24, 9,
                             m_defenderMap->GetShipList( ) );

      m_inputUI = new InputUI( "< Input >",
                               IntVec2{ m_width * 3 + 6, 11 },
                               24, 17,
                               attackerMap );
   }

   void SVGameInstance::Update( )
   {
      // @TODO: Get Input/Check end condition
      if ( m_statUI != nullptr )
      {
         m_statUI->SetTurn( GetTurnCount( ) );
      }

      if ( m_inputUI != nullptr )
      {
         m_inputUI->Update( );
         if ( m_inputUI->IsAbleToUseInput( ) )
         {
            IntVec2 targetPos = m_inputUI->GetInput( );
            targetPos.x;
         }
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

      if ( m_inputUI != nullptr )
      {
         m_inputUI->Draw( );
      }
   }
}