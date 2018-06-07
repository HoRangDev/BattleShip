#include "AIStatUI.h"

#include <sstream>

namespace BattleShip
{
   void AIStatUI::SetLatestSelection( int row, int col )
   {
      m_latestRow = row;
      m_latestCol = col;
   }

   void AIStatUI::SetRoundValue( int turnCount, int totalTurnCount, int repeat )
   {
      m_turnCount = turnCount;
      m_totalTurnCount = totalTurnCount;
      m_repeatCount = repeat;
   }

   void AIStatUI::DrawImpl( )
   {
      wborder( m_window, '|', '|', '-', '-', '+', '+', '+', '+' );
      mvwprintw( m_window, 0, m_name.length( ) / 2, m_name.c_str( ) );
      mvwprintw( m_window, 1, 2, "Pick (%d, %d)", m_latestCol, m_latestRow );
      mvwprintw( m_window, 2, 2, "Turn: %d", m_turnCount );
      mvwprintw( m_window, 3, 2, "Total Turn: %d", m_totalTurnCount );
      mvwprintw( m_window, 4, 2, "Repeat: %d", m_repeatCount );
      mvwprintw( m_window, 5, 2, "Avg Turn: %d", ( m_repeatCount > 0 ? ( m_totalTurnCount / m_repeatCount ) : 0 ) );
      wrefresh( m_window );
   }
}