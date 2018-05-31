// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#include "GameEndUI.h"

namespace BattleShip
{
   void GameEndUI::DrawImpl( )
   {
      curs_set( 0 );
      wborder( m_window, '|', '|', '-', '-', '+', '+', '+', '+' );

      wbkgd( m_window, COLOR_PAIR( ColorSet::GREENWHITE ) );
      wattron( m_window, COLOR_PAIR( ColorSet::GREENWHITE ) );
      mvwprintw( m_window, GetHeight( ) / 2, GetWidth( ) / 2 - 2, "Game Over!" );
      wattroff( m_window, COLOR_PAIR( ColorSet::GREENWHITE ) );
   }
}