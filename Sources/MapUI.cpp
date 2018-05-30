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

         IntVec2 origin{ };
         for ( int y = 0; y < maxY; ++y )
         {
            for ( int x = 0; x < maxX; ++x )
            {
               std::string printStr{ m_map->GetCharFrom( IntVec2{ x,y } ) };
               mvwprintw( m_window,
                          y + 1 + origin.y, x + 1 + origin.x,
                          printStr.c_str( ) );
               origin.x += m_space.x;
            }

            origin.x = 0;
            origin.y += m_space.y;
         }

         wrefresh( m_window );
      }
   }
}