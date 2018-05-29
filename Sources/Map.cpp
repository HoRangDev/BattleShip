#include "Map.h"
#include <iostream>

namespace BattleShip
{
   void Map::Print( ) const
   {
      for ( int y = 0; y < m_height; ++y )
      {
         for ( int x = 0; x < m_width; ++x )
         {
            std::cout << GetCharFrom( IntVec2( x, y ) ) << ' ';
         }

         std::cout << std::endl;
      }
   }
}