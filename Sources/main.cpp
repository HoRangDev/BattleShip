#include "App.h"

int main( )
{
   BattleShip::App app{ 
      10, 10,
      BattleShip::GameMode::SUPERVISED };

   return app.Run( );
}
