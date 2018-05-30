#include "MapUI.h"
#include "Map.h"

namespace BattleShip
{
   void MapUI::DrawImpl( )
   {
      if ( m_map != nullptr )
      {
         wborder( m_window, '|', '|', '-', '-', '+', '+', '+', '+' );
         mvwprintw( m_window, 0, m_name.length()/2, m_name.c_str( ) );

         int maxX = m_map->GetWidth( );
         int maxY = m_map->GetHeight( );

         // 위치 출력
         IntVec2 pos = GetPosition( );
         int offsetY = 0;

         // Column
         int offsetX = 0;
         int count = 0;
         while ( count < maxX )
         {
            mvprintw( pos.y + maxY + 2,
               ( pos.x + count ) + offsetX + 1,
                      std::to_string( count + 1 ).c_str() );
            offsetX += m_space.x;
            ++count;
         }

         // Row
         count = 0;
         while ( count < maxY )
         {
            std::string printingStr{ NationalToAlphabet( count ) };
            mvprintw( ( pos.y + count ) + offsetY + 1 ,
                      pos.x - 1,
                      printingStr.c_str( ) );
            offsetY += m_space.y;
            ++count;
         }

         IntVec2 origin{ };
         for ( int y = 0; y < maxY; ++y )
         {
            for ( int x = 0; x < maxX; ++x )
            {
               char typeChar = m_map->GetCharFrom( IntVec2{ x,y } );
               std::string printStr{ typeChar };

               ColorSet color = ColorSet::WHITEBLACK;
               // for coloring
               switch ( typeChar )
               {
               case '*':
                  color = ColorSet::WHITERED;
                  break;

               case 'X':
                  color = ColorSet::BLACKYELLOW;
                  break;

               case 'B':
                  color = ColorSet::REDWHITE;
                  break;

               case 'A':
                  color = ColorSet::BLACKCYAN;
                  break;

               case 'C':
                  color = ColorSet::WHITEGREEN;
                  break;

               case 'D':
                  color = ColorSet::WHITEMAGENTA;
                  break;
               }

               wattron( m_window, COLOR_PAIR( color ) );
               mvwprintw( m_window,
                          y + 1 + origin.y, x + 1 + origin.x,
                          printStr.c_str( ) );
               wattroff( m_window, COLOR_PAIR( color ) );
               origin.x += m_space.x;
            }

            origin.x = 0;
            origin.y += m_space.y;
         }

         wrefresh( m_window );
         refresh( );
      }
   }
}