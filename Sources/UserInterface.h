#pragma once

namespace BattleShip
{
   class UserInterface
   {
   public:
      UserInterface( unsigned int x, unsigned int y, unsigned int width, unsigned int height ) :
         m_x( x ), m_y( y ),
         m_width( width ), m_height( height ),
         m_drawable( true )
      {
      }

      void SetDrawable( bool drawable ) { m_drawable = drawable; }
      bool IsDrawable( ) const { return m_drawable; }

      unsigned int GetX( ) const { return m_x; }
      unsigned int GetY( ) const { return m_y; }

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
      unsigned int      m_x;
      unsigned int      m_y;

      unsigned int      m_width;
      unsigned int      m_height;

   };
}