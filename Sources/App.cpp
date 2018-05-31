#include "App.h"
#include "SVGameInstance.h"

#include <curses.h>
#include <string>

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
         init_pair( ColorSet::WHITEBLACK, COLOR_WHITE, COLOR_BLACK );
         init_pair( ColorSet::GREENBLACK, COLOR_GREEN, COLOR_BLACK );
         init_pair( ColorSet::REDBLACK, COLOR_RED, COLOR_BLACK );
         init_pair( ColorSet::YELLOWBLACK, COLOR_YELLOW, COLOR_BLACK );
         init_pair( ColorSet::WHITEGREEN, COLOR_WHITE, COLOR_GREEN );
         init_pair( ColorSet::BLACKYELLOW, COLOR_BLACK, COLOR_YELLOW );
         init_pair( ColorSet::BLACKCYAN, COLOR_BLACK, COLOR_CYAN );
         init_pair( ColorSet::REDWHITE, COLOR_RED, COLOR_WHITE );
         init_pair( ColorSet::WHITERED, COLOR_WHITE, COLOR_RED );
         init_pair( ColorSet::MAGENTAWHITE, COLOR_MAGENTA, COLOR_WHITE );
         init_pair( ColorSet::WHITEMAGENTA, COLOR_WHITE, COLOR_MAGENTA );

         mvprintw( 0, 0, m_name.c_str( ) );
         refresh( );

         m_gInst->Play( );
         
         auto end = endwin( );
         getch( );
         return end;
      }

      return 1;
   }
}