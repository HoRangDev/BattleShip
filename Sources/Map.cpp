#include "Map.h"
#include "Aircraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"

namespace BattleShip
{
   Map::Map( int width, int height ) :
      m_width( width ),
      m_height( height )
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
   }

   Map::~Map( )
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

   bool Map::Place( const IntVec2& pos, ShipType type, BatchAxis axis, int axisDirection )
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

   HitResult Map::HitCheck( const IntVec2& pos, bool hitResApply )
   {
      HitResult hitRes{ HitResultType::MISS, ShipType::SHIP_NONE };
      if ( pos.x < 0 || pos.y < 0 ||
           pos.x > m_width || pos.y > m_height )
      {
         hitRes.ship = ShipType::SHIP_ERROR;
      }
      else
      {
         if ( m_map[ pos.y ][ pos.x ] != ShipType::SHIP_NONE )
         {
            hitRes.type = HitResultType::HIT;
            hitRes.ship = m_map[ pos.y ][ pos.x ];

            if ( hitResApply )
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
      }

      return hitRes;
   }

   bool Map::AllDestroyed( ) const
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

   void Map::Reset( )
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
}