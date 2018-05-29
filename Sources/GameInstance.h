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
         while ( !m_bGameEnd )
         {
            this->Update( );
            this->Render( );
         }
      }

      virtual void Init( ) = 0;
      virtual void Update( ) = 0;
      virtual void Render( ) = 0;

      GameMode GetMode( ) const { return m_mode; }
      inline void IncreaseTurnCount( ) { ++m_turnCount; }
      int GetTurnCount( ) const { return m_turnCount; }

      Player& GetAttacker( ) { return ( *m_attacker ); }
      Player& GetDefender( ) { return ( *m_defender ); }

   protected:
      Player*  m_attacker;
      Player*  m_defender;

      bool     m_bGameEnd;

   private:
      GameMode m_mode;
      int m_width;
      int m_height;
      int m_turnCount;


   };
}