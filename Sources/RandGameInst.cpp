#include "RandGameInst.h"
#include "Player.h"
#include "ShipMap.h"
#include "HitMap.h"
#include "MapUI.h"
#include "StatUI.h"
#include "AIStatUI.h"

namespace BattleShip
{
   RandGameInst::RandGameInst( int width, int height, int repeat ) :
      m_maxRepeatCount( repeat ), m_repeatCount( 0 ),
      m_attackerMap( nullptr ), m_defenderMap( nullptr ),
      m_attackerMapUI( nullptr ), m_defenderMapUI( nullptr ),
      m_aiStatUI( nullptr ),
      m_totalTurn( 0 ),
      GameInstance( width, height, GameMode::RANDOM )
   {
   }

   void RandGameInst::Reset( )
   {
      Render( );
      std::this_thread::sleep_for( std::chrono::seconds( 1 ) );

      ++m_repeatCount;
      m_totalTurn += GetTurnCount( );

      m_aiStatUI->SetRoundValue( GetTurnCount( ),
                                 m_totalTurn,
                                 m_repeatCount );

      SetTurnCount( 0 );

      //@TODO: Set AI Stat UI parameter

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

      m_aiStatUI = new AIStatUI( "< Results >",
                                 IntVec2{ m_width * 3 + 6, 11 },
                                 24, 17 );
   }

   void RandGameInst::Update( )
   {
      if ( !m_bGameEnd )
      {
         if ( m_repeatCount < m_maxRepeatCount )
         {
            IntVec2 targetPos{ 0, 0 };
            targetPos.x = GenRandInt( 0, m_width );
            targetPos.y = GenRandInt( 0, m_height );

            auto hitRes = m_defender->HitCheck( targetPos );
            if ( m_attackerMap != nullptr )
            {
               m_aiStatUI->SetLatestSelection( targetPos.x, targetPos.y );
               bool isNewCheck = m_attackerMap->CheckAs( targetPos, hitRes.type );
               if ( isNewCheck )
               {
                  IncreaseTurnCount( );
               }
            }

            if ( m_defender->AllDestroyed( ) )
            {
               Reset( );
            }
         }
         else
         {
            m_bGameEnd = true;
         }
      }
   }

   void RandGameInst::Render( )
   {
      if ( !m_bGameEnd )
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

         if ( m_aiStatUI != nullptr )
         {
            m_aiStatUI->Draw( );
         }
      }
   }
}