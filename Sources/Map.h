#pragma once
#include "Common.h"

#include <vector>

namespace BattleShip
{
   class Map
   {
   public:
      Map( int width, int height ) :
         m_width( width ),
         m_height( height )
      {
      }

      virtual ~Map( ) { }

      virtual void Reset( ) { }
      int GetWidth( ) const { return m_width; }
      int GetHeight( ) const { return m_height; }

      virtual char GetCharFrom( const IntVec2& pos ) const = 0;

      // Debug method for map
      void Print( ) const;

   protected:
      int         m_width;
      int         m_height;

   };
}