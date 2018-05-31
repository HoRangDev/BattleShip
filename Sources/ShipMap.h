// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once
#include "Map.h"

namespace BattleShip
{
   class Ship;

   // 2D Array of ShipType
   using MapGrid = ShipType * *;
   using ShipList = std::vector<Ship*>;

   class ShipMap : public Map
   {
   public:
      ShipMap( int width, int height );
      ~ShipMap( );

      /*
      * @brief Ship을 위한 일종의 Factory method 이다. Place 로 전달된 배 타입에 따라 적절하게 배치후 Ship 객체를 저장한다.
      * @param pos   배가 배치될 origin 위치 [좌측 상단부터 (0,0)로 시작하여 우측 하단 (width, height)]
      * @param type  배의 타입
      * @param axis  배가 어느 축을 기준으로 배치될지 결정함.
      * @param axisDirection Axis 를 기준으로 Delta 방향으로 배치됨
      * @return      배가 배치될 수 있는지 확인함.
      **/
      bool Place( const IntVec2& pos, ShipType type, BatchAxis axis, int axisDirection );

      /*
      * @brief 주어진 위치에 배가 위치하고 있는지 체크한다. 만약 Hit 했다면 Ship 의 Hit Count 를 증가시킨다.
      만약 이미 Destroy 되었거나 올바르지 않은 위치가 주어진다면 ERROR를 반환한다.
      * @param pos   배가 있는지 체크할 위치
      * @param hitCounting Hit 정보를 Ship 에 적용할지 정합니다.
      * @return      Hit 결과
      **/
      HitResult HitCheck( const IntVec2& pos, bool hitCounting = true );

      /*
      * @brief 기본적인 6개의 배를 Map 상에 랜덤하게 배치한다. (1 Aircraft, 1 BattleShip, 2 Crusier, 2 Destroyer)
      */
      void PlaceRandomly( );

      /*
      * @brief 모든 배가 파괴되었는지 체크합니다.
      **/
      bool AllDestroyed( ) const;

      virtual void Reset( ) override;

      virtual char GetCharFrom( const IntVec2& pos ) const override;

      ShipList& GetShipList( ) { return m_ships; }

   private:
      HitResult ConstHitCheck( const IntVec2& pos ) const;

   private:
      MapGrid     m_map;
      ShipList    m_ships;

   };
}