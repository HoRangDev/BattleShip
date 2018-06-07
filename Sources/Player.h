// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once
#include "Common.h"

namespace BattleShip
{
   class Map;
   class Player
   {
   public:
      Player( int width, int height, PlayerType type );
      ~Player( );

      /*
      * @brief �־��� ��ġ�� �谡 ��ġ�ϰ� �ִ��� üũ�Ѵ�. ���� Hit �ߴٸ� Ship �� Hit Count �� ������Ų��.
      ���� �̹� Destroy �Ǿ��ų� �ùٸ��� ���� ��ġ�� �־����ٸ� ERROR�� ��ȯ�Ѵ�. (Wrapper method of Map::HitCheck)
      * @param pos   �谡 �ִ��� üũ�� ��ġ
      * @return      Hit ���
      **/
      HitResult HitCheck( const IntVec2& pos );

      /*
      * @brief Wrapper method of Map::AllDestroyed
      **/
      bool AllDestroyed( ) const;

      PlayerType GetType( ) const { return m_type; }
      Map* GetMap( ) { return m_map; }

   protected:
      Map*     m_map;

   private:
      PlayerType m_type;

   };
}