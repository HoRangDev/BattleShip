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
      * @brief �⺻���� 6���� �踦 Map �� �����ϰ� ��ġ�Ѵ�. (1 Aircraft, 1 BattleShip, 2 Crusier, 2 Destroyer)
      */
      void PlaceRandomly( );

      /*
      * @brief Ship�� ���� ������ Factory method �̴�. Place �� ���޵� �� Ÿ�Կ� ���� �����ϰ� ��ġ�� Ship ��ü�� �����Ѵ�.
      * @param pos   �谡 ��ġ�� origin ��ġ
      * @param type  ���� Ÿ��
      * @param axis  �谡 ��� ���� �������� ��ġ���� ������.
      * @param delta Axis �� �������� Delta �������� ��ġ��
      * @return      �谡 ��ġ�� �� �ִ��� Ȯ����.
      **/
      bool Place( const IntVec2& pos, ShipType type, BatchAxis axis, int delta );

      /*
      * @brief �־��� ��ġ�� �谡 ��ġ�ϰ� �ִ��� üũ�Ѵ�. ���� Hit �ߴٸ� Ship �� Hit Count �� ������Ų��.
      ���� �̹� Destroy �Ǿ��ų� �ùٸ��� ���� ��ġ�� �־����ٸ� ERROR�� ��ȯ�Ѵ�.
      * @param pos   �谡 �ִ��� üũ�� ��ġ
      * @return      Hit ���
      **/
      HitResultType HitCheck( const IntVec2& pos );

   private:
      MapGrid     m_map;
      ShipList    m_ships;

   };
}