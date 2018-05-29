#include "ShipMap.h"
#include "Aircraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"

namespace BattleShip
{
   ShipMap::ShipMap( int width, int height ) :
      Map( width, height )
   {
      m_map = new ShipType*[ height ];
      for ( int y = 0; y < m_height; ++y )
      {
         m_map[ y ] = new ShipType[ m_width ];

         // Initialize
         for ( int x = 0; x < m_width; ++x )
         {
            m_map[ y ][ x ] = ShipType::SHIP_NONE;
         }
      }

      Print( );
   }

   ShipMap::~ShipMap( )
   {
      if ( m_map != nullptr )
      {
         for ( int y = 0; y < m_height; ++y )
         {
            if ( m_map[ y ] != nullptr )
            {
               delete[ ] m_map[ y ];
               m_map[ y ] = nullptr;
            }
         }

         delete[ ] m_map;
         m_map = nullptr;
      }
   }

   bool ShipMap::Place( const IntVec2& pos, ShipType type, BatchAxis axis, int axisDirection )
   {
      Ship* newShip = nullptr;
      switch ( type )
      {
      case ShipType::AIRCRAFT:
         newShip = new Aircraft( pos );
         break;

      case ShipType::BATTLESHIP:
         newShip = new BattleShip( pos );
         break;

      case ShipType::CRUISER:
         newShip = new Cruiser( pos );
         break;

      case ShipType::DESTROYER:
         newShip = new Destroyer( pos );
         break;

      default:
         return false;
      }

      IntVec2 currentPos{ pos };
      IntVec2 finalPos{ pos };

      int deltaAxis = newShip->GetSize( );
      deltaAxis *= axisDirection;

      IntVec2 delta{ 0, 0 };
      switch ( axis )
      {
      case BatchAxis::XAXIS:
         delta.x = axisDirection;
         finalPos.x += deltaAxis;
         break;

      case BatchAxis::YAXIS:
         delta.y = axisDirection;
         finalPos.y += deltaAxis;
         break;
      }

      while ( currentPos != finalPos )
      {
         // 맵에 배가 배치될때는 Hit 처리가 하나도 되지 않은것으로 가정합니다.
         // 그러므로 주어진 위치에 배가 없으면 HitResult 로 Miss 와 배가 없음이 반환되어야 합니다.
         auto hitRes = HitCheck( currentPos, false );
         if ( hitRes.type != HitResultType::MISS ||
              hitRes.ship != ShipType::SHIP_NONE )
         {
            SAFE_DELETE( newShip );
            return false;
         }

         currentPos += delta;
      }

      // 이제 맵에 실제로 배치할 준비가 됨.
      currentPos = pos;
      while ( currentPos != finalPos )
      {
         m_map[ currentPos.y ][ currentPos.x ] = type;
         currentPos += delta;
      }

      m_ships.push_back( newShip );
      return true;
   }

   HitResult ShipMap::HitCheck( const IntVec2& pos, bool hitCounting )
   {
      HitResult hitRes = ConstHitCheck( pos );
      if ( hitRes.type == HitResultType::HIT )
      {
         if ( hitCounting )
         {
            for ( auto ship : m_ships )
            {
               if ( ship->GetPosition( ) == pos )
               {
                  ship->IncreaseHitCount( );
                  if ( ship->IsDestroyed( ) )
                  {
                     hitRes.type = HitResultType::DESTROY;
                  }
               }
            }
         }
      }

      return hitRes;
   }

   HitResult ShipMap::ConstHitCheck( const IntVec2& pos ) const
   {
      HitResult hitRes{ HitResultType::MISS, ShipType::SHIP_NONE };
      if ( !IsInBound( pos ) )
      {
         hitRes.ship = ShipType::SHIP_ERROR;
      }
      else
      {
         if ( m_map[ pos.y ][ pos.x ] != ShipType::SHIP_NONE )
         {
            hitRes.type = HitResultType::HIT;
            hitRes.ship = m_map[ pos.y ][ pos.x ];
         }
      }

      return hitRes;
   }

   bool ShipMap::AllDestroyed( ) const
   {
      for ( auto ship : m_ships )
      {
         if ( !ship->IsDestroyed( ) )
         {
            return false;
         }
      }

      return true;
   }

   void ShipMap::Reset( )
   {
      // Reset grid
      for ( int y = 0; y < m_height; ++y )
      {
         for ( int x = 0; x < m_width; ++x )
         {
            m_map[ y ][ x ] = ShipType::SHIP_NONE;
         }
      }

      // Reset ship list
      for ( auto ship : m_ships )
      {
         delete ship;
      }
      m_ships.clear( );
   }

   char ShipMap::GetCharFrom( const IntVec2& pos ) const
   {
      return ShipTypeToChar( ConstHitCheck( pos ).ship );
   }
}