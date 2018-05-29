#pragma once
#include "Common.h"

#include <vector>

namespace BattleShip
{
   class Ship;
   
   // 2D Array of ShipType
   using MapGrid = ShipType**;
   using ShipList = std::vector<Ship*>;

   class Map
   {
   public:
      Map( int width, int height );
      ~Map( );

      /*
      * @brief Ship�� ���� ������ Factory method �̴�. Place �� ���޵� �� Ÿ�Կ� ���� �����ϰ� ��ġ�� Ship ��ü�� �����Ѵ�.
      * @param pos   �谡 ��ġ�� origin ��ġ [���� ��ܺ��� (0,0)�� �����Ͽ� ���� �ϴ� (width, height)]
      * @param type  ���� Ÿ��
      * @param axis  �谡 ��� ���� �������� ��ġ���� ������.
      * @param axisDirection Axis �� �������� Delta �������� ��ġ��
      * @return      �谡 ��ġ�� �� �ִ��� Ȯ����.
      **/
      bool Place( const IntVec2& pos, ShipType type, BatchAxis axis, int axisDirection );

    

      /*
      * @brief �־��� ��ġ�� �谡 ��ġ�ϰ� �ִ��� üũ�Ѵ�. ���� Hit �ߴٸ� Ship �� Hit Count �� ������Ų��.
      ���� �̹� Destroy �Ǿ��ų� �ùٸ��� ���� ��ġ�� �־����ٸ� ERROR�� ��ȯ�Ѵ�.
      * @param pos   �谡 �ִ��� üũ�� ��ġ
      * @param hitResApply Hit ������ Ship �� �������� ���մϴ�.
      * @return      Hit ���
      **/
      HitResult HitCheck( const IntVec2& pos, bool hitResApply = true );

      /*
      * @brief �⺻���� 6���� �踦 Map �� �����ϰ� ��ġ�Ѵ�. (1 Aircraft, 1 BattleShip, 2 Crusier, 2 Destroyer)
      */
      void PlaceRandomly( );

      /*
      * @brief ��� �谡 �ı��Ǿ����� üũ�մϴ�.
      **/
      bool AllDestroyed( ) const;

   private:
      int         m_width;
      int         m_height;
      MapGrid     m_map;
      ShipList    m_ships;

   };
}