// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#include "UserInterface.h"

namespace BattleShip
{
   void UserInterface::SetDrawable( bool drawable )
   {
      m_drawable = drawable;
      if ( !drawable )
      {
         this->Clear( );
      }
      else
      {
         Draw( );
      }

      wrefresh( m_window );
   }
   void UserInterface::Clear( )
   {
      for ( int y = 0; y < m_height; ++y )
      {
         for ( int x = 0; x < m_width; ++x )
         {
            mvwprintw( m_window, y, x, " " );
         }
      }
   }
}