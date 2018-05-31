#include "InputUI.h"
#include "Map.h"

namespace BattleShip
{
   void InputUI::Update( )
   {
      if ( IsDrawable( ) )
      {
         m_bIsAbleToUseInput = false;

         constexpr unsigned int MaxLength = 5;
         char input[ MaxLength ] = { 0, };
         mvwscanw( m_window, 1, m_inputMessageStr.length( ) + 1, "%s", input );

         std::string temp = input;
         int idx = 0;

         char inputRow = '-';
         int row = 0;
         for ( ; idx < temp.length( ); ++idx )
         {
            bool isInUpper = temp[ idx ] >= 'A' && temp[ idx ] <= 'Z';
            bool isInLower = temp[ idx ] >= 'a' && temp[ idx ] <= 'z';
            if ( isInLower || isInUpper )
            {
               inputRow = temp[ idx ];
               row = AlphaToNaturalNumber( inputRow );
               if ( row >= 0 )
               {
                  m_bIsAbleToUseInput = true;
               }
               break;
            }
         }

         temp = temp.substr( idx + 1 );

         int col = std::atoi( temp.c_str( ) ) - 1;
         if ( m_attackerMap == nullptr ||
              col < 0 ||
              col >= m_attackerMap->GetWidth( ) )
         {
            m_bIsAbleToUseInput = false;
         }

         m_input.x = col;
         m_input.y = row;
      }
   }

   void InputUI::DrawImpl( )
   {
      curs_set( 1 );
      wborder( m_window, '|', '|', '-', '-', '+', '+', '+', '+' );
      mvwprintw( m_window, 0, m_name.length( ) / 2, m_name.c_str( ) );
      mvwprintw( m_window, 1, 1, m_inputMessageStr.c_str( ) );
      // clear input
      mvwprintw( m_window, 1, m_inputMessageStr.length( ) + 1, "  " );

      auto color = ColorSet::WHITEBLACK;
      switch ( m_latestHit.type )
      {
      case HitResultType::HIT:
         color = ColorSet::GREENBLACK;
         break;

      case HitResultType::MISS:
         color = ColorSet::YELLOWBLACK;
         break;

      case HitResultType::DESTROY:
         color = ColorSet::YELLOWBLACK;
         break;
      }

      // CLEAR
      std::string space = " ";
      for ( int x = 1; x < GetWidth( ); ++x )
      {
         mvwprintw( m_window, 2, x, space.c_str( ) );
      }

      // write result
      wattron( m_window, COLOR_PAIR( color ) );
      mvwprintw( m_window, 2, 1, HitResultToString( m_latestHit ).c_str( ) );
      wattroff( m_window, COLOR_PAIR( color ) );
      wrefresh( m_window );
   }
}