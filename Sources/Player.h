#pragma once
#include "Common.h"

#include <array>

namespace BattleShip
{
   class Map;
   class Player
   {
   public:
      Player( );
      ~Player( );

      /*
      * @brief �־��� ��ġ�� �谡 ��ġ�ϰ� �ִ��� üũ�Ѵ�. ���� Hit �ߴٸ� Ship �� Hit Count �� ������Ų��.
      ���� �̹� Destroy �Ǿ��ų� �ùٸ��� ���� ��ġ�� �־����ٸ� ERROR�� ��ȯ�Ѵ�. (Wrapper method for map)
      * @param pos   �谡 �ִ��� üũ�� ��ġ
      * @return      Hit ���
      **/
      HitResultType HitCheck( const IntVec2& pos );

   protected:
      Map*     m_map;

   };
}