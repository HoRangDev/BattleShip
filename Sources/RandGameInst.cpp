#include "RandGameInst.h"
#include "Player.h"
#include "ShipMap.h"
#include "HitMap.h"
#include "MapUI.h"
#include "StatUI.h"

namespace BattleShip
{
   RandGameInst::RandGameInst( int width, int height ) :
      m_attackerMap( nullptr ), m_defenderMap( nullptr ),
      m_attackerMapUI( nullptr ), m_defenderMapUI( nullptr ),
      GameInstance( width, height, GameMode::RANDOM )
   {
   }

   void RandGameInst::Reset( )
   {
      if ( m_attackerMap != nullptr )
      {
         m_attackerMap->Reset( );
      }
      if ( m_defenderMap != nullptr )
      {
         m_defenderMap->Reset( );
         m_defenderMap->PlaceRandomly( );
      }
   }

   void RandGameInst::Init( )
   {
      m_attackerMap = static_cast< HitMap* >( m_attacker->GetMap( ) );
      m_defenderMap = static_cast< ShipMap* >( m_defender->GetMap( ) );
      m_defenderMap->PlaceRandomly( );

      m_defenderMapUI = new MapUI(
         "Defender",
         IntVec2{ 3, 2 },
         m_width * 3 + 2, m_height + 2,
         m_defenderMap );
      
      m_attackerMapUI = new MapUI(
         "AIPlayer",
         IntVec2{ 3, 6 + m_height },
         m_width * 3 + 2, m_height + 2,
         m_attackerMap );

      m_defenderMapUI->SetSpace( { 2, 0 } );
      m_attackerMapUI->SetSpace( { 2, 0 } );

      m_statUI = new StatUI( "< Status >",
                             { m_width * 3 + 6, 2 },
                             24, 9 );
      m_statUI->SetShipMap( m_defenderMap );
      m_statUI->SetTurn( GetTurnCount( ) );
   }

   void RandGameInst::Update( )
   {
      std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
      Reset( );
   }

   void RandGameInst::Render( )
   {
      if ( m_attackerMapUI != nullptr )
      {
         m_attackerMapUI->Draw( );
      }

      if ( m_defenderMapUI != nullptr )
      {
         m_defenderMapUI->Draw( );
      }

      if ( m_statUI != nullptr )
      {
         m_statUI->Draw( );
      }
   }
}