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
      * @param hitCounting Hit ������ Ship �� �������� ���մϴ�.
      * @return      Hit ���
      **/
      HitResult HitCheck( const IntVec2& pos, bool hitCounting = true );

      /*
      * @brief �⺻���� 6���� �踦 Map �� �����ϰ� ��ġ�Ѵ�. (1 Aircraft, 1 BattleShip, 2 Crusier, 2 Destroyer)
      */
      void PlaceRandomly( );

      /*
      * @brief ��� �谡 �ı��Ǿ����� üũ�մϴ�.
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