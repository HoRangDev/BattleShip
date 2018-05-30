#include "App.h"
#include "SVGameInstance.h"

#include <curses.h>

namespace BattleShip
{
   App::App( int width, int height, GameMode mode ) :
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
      // @TODO: Add Initialize of pdcurses(ncurses)
      if ( m_gInst != nullptr )
      {
         initscr( );
         curs_set( 0 );

         m_gInst->Play( );

         return endwin( );
      }

      return 1;
   }
}