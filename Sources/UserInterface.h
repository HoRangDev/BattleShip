#pragma once
#include "Common.h"

namespace BattleShip
{
   class UserInterface
   {
   public:
      UserInterface( const IntVec2& position, 
                     unsigned int width, unsigned int height ) :
         m_position( position ),
         m_width( width ), m_height( height ),
         m_drawable( true )
      {
      }

      void SetDrawable( bool drawable ) { m_drawable = drawable; }
      bool IsDrawable( ) const { return m_drawable; }

      IntVec2 GetPosition( ) const { return m_position; }

      unsigned int GetWidth( ) const { return m_width; }
      unsigned int GetHeight( ) const { return m_height; }

      virtual void Draw( ) final
      {
         if ( m_drawable )
         {
            this->DrawImpl( );
         }
      }

   protected:
      virtual void DrawImpl( ) = 0;

   private:
      bool              m_drawable;
      IntVec2           m_position;

      unsigned int      m_width;
      unsigned int      m_height;

   };
}