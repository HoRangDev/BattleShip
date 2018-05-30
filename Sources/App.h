#pragma once
#include "Common.h"

namespace BattleShip
{
   class App
   {
   public:
      App( 
         const std::string& name,
         int windowWidth, int windowHeight,
         int width, int height, GameMode mode );
      ~App( );

      int Run( );

   private:
      std::string m_name;
      int   m_windowWidth;
      int   m_windowHeight;
      class GameInstance* m_gInst;

   };
}