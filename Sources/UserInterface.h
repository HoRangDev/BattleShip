// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once
#include "Common.h"

namespace BattleShip
{
   class UserInterface
   {
   public:
      UserInterface(
         const std::string& name,
         const IntVec2& position,
         unsigned int width, unsigned int height ) :
         m_name( name ),
         m_window( nullptr ),
         m_position( position ),
         m_width( width ), m_height( height ),
         m_drawable( true )
      {
         m_window = newwin( m_height, m_width, m_position.y, m_position.x );
      }

      virtual ~UserInterface( )
      {
         delwin( m_window );
      }

      void SetDrawable( bool drawable );
      bool IsDrawable( ) const { return m_drawable; }

      IntVec2 GetPosition( ) const { return m_position; }

      unsigned int GetWidth( ) const { return m_width; }
      unsigned int GetHeight( ) const { return m_height; }

      virtual void Draw( ) final
      {
         if ( m_drawable )
         {
            Clear( );
            this->DrawImpl( );
         }
      }

      virtual void Clear( ) final;

   protected:
      virtual void DrawImpl( ) = 0;

   protected:
      WINDOW* m_window;
      std::string m_name;

   private:
      bool              m_drawable;
      IntVec2           m_position;

      unsigned int      m_width;
      unsigned int      m_height;

   };
}