// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once
#include "Common.h"

namespace BattleShip
{
   class Player;
   class Map;
   class GameInstance
   {
   public:
      GameInstance( int width, int height, GameMode mode );
      virtual ~GameInstance( );

      virtual void Play( ) final
      {
         this->Init( );
         m_bGameEnd = false;

         // Pre-Render
         this->Render( );

         while ( !m_bGameEnd )
         {
            this->Update( );
            this->Render( );
         }

         std::this_thread::sleep_for( std::chrono::seconds( 1 ) ); // wait for 1sec to end
      }

      GameMode GetMode( ) const { return m_mode; }
      inline void IncreaseTurnCount( ) { ++m_turnCount; }
      int GetTurnCount( ) const { return m_turnCount; }

      Player& GetAttacker( ) { return ( *m_attacker ); }
      Player& GetDefender( ) { return ( *m_defender ); }

   protected:
      virtual void Init( ) = 0;
      virtual void Update( ) = 0;
      virtual void Render( ) = 0;

   protected:
      Player*  m_attacker;
      Player*  m_defender;

      bool     m_bGameEnd;

      HitResultType**  m_hitMap;

      int m_width;
      int m_height;

   private:
      GameMode m_mode;
      int m_turnCount;


   };
}