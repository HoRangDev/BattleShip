// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#include "StatUI.h"
#include "Ship.h"

#include <sstream>

namespace BattleShip
{
   void StatUI::DrawImpl( )
   {
      if ( !m_ships.empty( ) )
      {
         int y = 1;
         const int x = 2;
         wborder( m_window, '|', '|', '-', '-', '+', '+', '+', '+' );
         mvwprintw( m_window, 0, m_name.length( ) / 2, m_name.c_str( ) );

         wattron( m_window, COLOR_PAIR( ColorSet::GREENBLACK ) );
         mvwprintw( m_window, y, x, ("Turn: " + std::to_string( m_turn )).c_str( ) );
         wattroff( m_window, COLOR_PAIR( ColorSet::GREENBLACK ) );

         for ( auto ship : m_ships )
         {
            std::stringstream ss;

            // TYPE: Size*(ship character)
            if ( ship != nullptr )
            {
               ColorSet color = ColorSet::WHITEBLACK;
               char typeChar = ShipTypeToChar( ship->GetType( ) );
               ss << ship->GetName( ) << ": ";
               for ( int count = 0; count < ship->GetSize( ); ++count )
               {
                  ss << typeChar;
               }

               if ( ship->IsDestroyed( ) )
               {
                  color = ColorSet::REDBLACK;
               }

               wattron( m_window, COLOR_PAIR( color ) );
               mvwprintw( m_window, y + 1, x, ss.str( ).c_str( ) );
               wattroff( m_window, COLOR_PAIR( color ) );

               ++y;
            }
         }

         wrefresh( m_window );
      }
   }
}