#include "SVGameInstance.h"

#include <iostream>
#include <curses.h>

// Test curses
int main( )
{
   BattleShip::SVGameInstance ginst{ 10, 10 };
   ginst.Play( );
   //initscr( );

   //keypad( stdscr, true );
   //curs_set( 0 );
   //noecho( );

   //char userName[ 8 ];
   //printw( "Hello~" );
   //scanw( "%s", userName );

   //printw( "%s\n", userName );
   //refresh( );
   //getch( );
   //endwin( );
   return 0;
}
