#include "Map.h"
#include "Ship.h"

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
      // @TODO: Implement allocation of ship by type
      switch ( type )
      {
      case ShipType::BATTLESHIP:
         break;

      case ShipType::AIRCRAFT:
         break;

      case ShipType::CRUISER:
         break;

      case ShipType::DESTROYER:
         break;

      default:
         return false;
      }

      if ( newShip != nullptr )
      {

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
            // �ʿ� �谡 ��ġ�ɶ��� Hit ó���� �ϳ��� ���� ���������� �����մϴ�.
            // �׷��Ƿ� �־��� ��ġ�� �谡 ������ HitResult �� Miss �� �谡 ������ ��ȯ�Ǿ�� �մϴ�.
            auto hitRes = HitCheck( currentPos, false );
            if ( hitRes.type != HitResultType::MISS ||
                 hitRes.ship != ShipType::SHIP_NONE )
            {
               return false;
            }

            currentPos += delta;
         }

         // ���� �ʿ� ������ ��ġ�� �غ� ��.
         currentPos = pos;
         while ( currentPos != finalPos )
         {
            m_map[ currentPos.y ][ currentPos.x ] = type;
            currentPos += delta;
         }

         return true;
      }

      return false;
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
}