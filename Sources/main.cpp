#include "App.h"

int main( )
{  
   constexpr int WindowWidth = 48;
   constexpr int WindowHeight = 27;
   constexpr int BoardWidth = 10;
   constexpr int BoardHeight = 10;
   BattleShip::App app{ 
      "бс < BattleShip > бс",
      WindowWidth, WindowHeight,
      BoardWidth, BoardHeight,
      BattleShip::GameMode::SUPERVISED };

   return app.Run( );
}
