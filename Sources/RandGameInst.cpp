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
      m_findStage( FindStage::RandomPick ),
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

   IntVec2 RandGameInst::FindNext( )
   {
      IntVec2 res;
      switch ( m_findStage )
      {
      case FindStage::RandomPick:
         res.x = GenRandInt( 0, m_width );
         res.y = GenRandInt( 0, m_height );
         break;

      case FindStage::SearchDir:
         res = ( m_findOrigin + DirectionToVec( m_findDir ) );
         break;

      case FindStage::Search:
      case FindStage::SearchOpposite:
         res = ( m_curFindPos + DirectionToVec( m_findDir ) );
         m_curFindPos = res;
         break;
      }

      return res;
   }

   void RandGameInst::Update( )
   {
      if ( !m_bGameEnd )
      {
         if ( m_repeatCount < m_maxRepeatCount )
         {
            IntVec2 targetPos{ FindNext( ) };
            
            auto hitRes = m_defender->HitCheck( targetPos );
            bool isNewCheck = m_attackerMap->CheckAs( targetPos, hitRes.type );
            switch ( hitRes.type )
            {
            case HitResultType::HIT:
               if ( isNewCheck )
               {
                  if ( m_findStage == FindStage::RandomPick )
                  {
                     m_findOrigin = targetPos;
                     m_findDir = Direction::DOWN;
                     m_findStage = FindStage::SearchDir;
                  }
                  else if ( m_findStage == FindStage::SearchDir )
                  {
                     m_curFindPos = targetPos;
                     m_findStage = FindStage::Search;
                  }

                  break;
               }

            case HitResultType::MISS:
               if ( m_findStage == FindStage::SearchDir )
               {
                  m_findDir = NextDirection( m_findDir );
                  if ( m_findDir == Direction::NONE )
                  {
                     m_findStage = FindStage::RandomPick;
                  }
               }
               else if ( m_findStage == FindStage::Search )
               {
                  m_findDir = OppositeOf( m_findDir );
                  m_curFindPos = m_findOrigin;
                  m_findStage = FindStage::SearchOpposite;
               }
               else if ( m_findStage == FindStage::SearchOpposite )
               {
                  m_findStage = FindStage::SearchDir;
                  m_findDir = Direction::DOWN;
               }
               break;

            case HitResultType::DESTROY:
               m_findStage = FindStage::RandomPick;
               break;
            }

            if ( isNewCheck )
            {
               IncreaseTurnCount( );
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