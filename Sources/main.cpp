#include "App.h"

int main( )
{
   BattleShip::App app{ 
      "бс < BattleShip > бс",
      55, 35,
      10, 10,
      BattleShip::GameMode::SUPERVISED };

   return app.Run( );
}
