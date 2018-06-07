#include "AIStatUI.h"

#include <sstream>

namespace BattleShip
{
   void AIStatUI::SetLatestSelection( int row, int col )
   {
      std::stringstream ss;
      char rowChar = NaturalNumberToAlpha( row );
      ss << "Latest Selection: " << rowChar << ' ' << ( col - 1 );
      m_selectionMsg = ss.str( );
      ss.clear( );
   }

   void AIStatUI::DrawImpl( )
   {

   }
}