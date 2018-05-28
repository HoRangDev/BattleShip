#pragma once
#include "Common.h"

#include <vector>

namespace BattleShip
{
   struct HitResult
   {
      HitResultType type;
      ShipType      ship;
   };

   // 2D Array of ShipType
   using MapGrid = ShipType**;
   using ShipList = std::vector<Ship*>;

   class Ship;
   class Map
   {
   public:
      Map( int width, int height );
      ~Map( );

      /*
      * @brief 기본적인 6개의 배를 Map 상에 랜덤하게 배치한다. (1 Aircraft, 1 BattleShip, 2 Crusier, 2 Destroyer)
      */
      void PlaceRandomly( );

      /*
      * @brief Ship을 위한 일종의 Factory method 이다. Place 로 전달된 배 타입에 따라 적절하게 배치후 Ship 객체를 저장한다.
      * @param pos   배가 배치될 origin 위치
      * @param type  배의 타입
      * @param axis  배가 어느 축을 기준으로 배치될지 결정함.
      * @param delta Axis 를 기준으로 Delta 방향으로 배치됨
      * @return      배가 배치될 수 있는지 확인함.
      **/
      bool Place( const IntVec2& pos, ShipType type, BatchAxis axis, int delta );

      /*
      * @brief 주어진 위치에 배가 위치하고 있는지 체크한다. 만약 Hit 했다면 Ship 의 Hit Count 를 증가시킨다.
      만약 이미 Destroy 되었거나 올바르지 않은 위치가 주어진다면 ERROR를 반환한다.
      * @param pos   배가 있는지 체크할 위치
      * @return      Hit 결과
      **/
      HitResultType HitCheck( const IntVec2& pos );

      /*
      * @brief 모든 배가 파괴되었는지 체크합니다.
      **/
      bool AllDestroyed( ) const;

   private:
      MapGrid     m_map;
      ShipList    m_ships;

   };
}