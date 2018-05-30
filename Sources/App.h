#pragma once
#include "Common.h"

namespace BattleShip
{
   class App
   {
   public:
      App( int width, int height, GameMode mode );
      ~App( );

      int Run( );

   private:
      class GameInstance* m_gInst;

   };
}