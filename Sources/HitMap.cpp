#include "HitMap.h"
#include <iostream>

namespace BattleShip
{
   HitMap::HitMap( int width, int height ) :
      Map( width, height )
   {
      m_hitMap = new HitResultType*[ height ];
      for ( int y = 0; y < m_height; ++y )
      {
         m_hitMap[ y ] = new HitResultType[ m_width ];

         // Initilaize
         for ( int x = 0; x < m_width; ++x )
         {
            m_hitMap[ y ][ x ] = HitResultType::NONE;
         }
      }
   }

   HitMap::~HitMap( )
   {
      if ( m_hitMap != nullptr )
      {
         for ( int y = 0; y < m_height; ++y )
         {
            if ( m_hitMap[ y ] != nullptr )
            {
               delete[ ] m_hitMap[ y ];
               m_hitMap[ y ] = nullptr;
            }
         }

         delete[ ] m_hitMap;
         m_hitMap = nullptr;
      }
   }

   bool HitMap::CheckAs( const IntVec2& pos, HitResultType type )
   {
      if ( IsInBound( pos ) )
      {
         if ( m_hitMap[ pos.y ][ pos.x ] != type )
         {
            m_hitMap[ pos.y ][ pos.x ] = type;
            return true;
         }
      }

      return false;
   }

   char HitMap::GetCharFrom( const IntVec2& pos ) const
   {
      if ( !IsInBound( pos ) )
      {
         return '-';
      }

      return HitResultTypeToChar( m_hitMap[ pos.y ][ pos.x ] );
   }

   void HitMap::Reset( )
   {
      for ( int y = 0; y < m_height; ++y )
      {
         for ( int x = 0; x < m_width; ++x )
         {
            m_hitMap[ y ][ x ] = HitResultType::NONE;
         }
      }
   }
}