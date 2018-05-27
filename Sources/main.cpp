#include <iostream>
#include <curses.h>

// Test curses
int main( )
{
   initscr( );

   keypad( stdscr, true );
   curs_set( 0 );
   noecho( );

   char userName[ 8 ];
   printw( "Hello~" );
   scanw( "%s", userName );

   printw( "%s\n", userName );
   refresh( );
   getch( );
   endwin( );
   return 0;
}
