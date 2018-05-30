#include "App.h"
#include "SVGameInstance.h"

#include <curses.h>

namespace BattleShip
{
   App::App( 
      const std::string& name,
      int windowWidth, int windowHeight, int width, int height, GameMode mode ) :
      m_name( name ),
      m_windowWidth( windowWidth ),
      m_windowHeight( windowHeight ),
      m_gInst( nullptr )
   {
      switch ( mode )
      {
      case GameMode::SUPERVISED:
         m_gInst = new SVGameInstance( width, height );
         break;

      case GameMode::RANDOM:
         // @TODO: Impl allocation of RandGameInstance
         break;

      case GameMode::OPTIMAL:
         // @TODO: Impl allocation of OptGameInstance
         break;
      }
   }

   App::~App( )
   {
      SAFE_DELETE( m_gInst );
   }

   int App::Run( )
   {
      if ( m_gInst != nullptr )
      {
         initscr( );
         curs_set( 0 );
         resize_term( m_windowHeight, m_windowWidth );

         // Color settings
         start_color( );
         init_pair( B_COLOR_GREENBLACK, COLOR_GREEN, COLOR_BLACK );
         init_pair( B_COLOR_REDBLACK, COLOR_RED, COLOR_BLACK );
         init_pair( B_COLOR_YELLOWBLACK, COLOR_YELLOW, COLOR_BLACK );

         mvprintw( 0, 0, m_name.c_str( ) );

         refresh( );

         m_gInst->Play( );

         return endwin( );
      }

      return 1;
   }
}