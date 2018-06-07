// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#include "App.h"

int main( )
{  
   constexpr int WindowWidth = 62;
   constexpr int WindowHeight = 30;
   constexpr int BoardWidth = 10;
   constexpr int BoardHeight = 10;

   BattleShip::App app{
      "бс < BattleShip > бс",
      WindowWidth, WindowHeight,
      BoardWidth, BoardHeight,
      BattleShip::GameMode::RANDOM, 30 };

   return app.Run( );
}
