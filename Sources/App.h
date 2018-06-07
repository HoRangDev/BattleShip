// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
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
         int width, int height, GameMode mode, int repeat = 1 );
      ~App( );

      int Run( );

   private:
      std::string m_name;
      int   m_windowWidth;
      int   m_windowHeight;
      class GameInstance* m_gInst;

   };
}