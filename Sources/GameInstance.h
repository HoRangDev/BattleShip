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

      virtual void Init( ) = 0;
      virtual void Update( ) = 0;
      virtual void Render( ) = 0;

      GameMode GetMode( ) const { return m_mode; }
      int GetTurnCount( ) const { return m_turnCount; }

   protected:
      GameMode m_mode;
      int m_width;
      int m_height;
      int m_turnCount;

      Player*  m_attacker;
      Player*  m_defender;
      Map*     m_map;

   };
}