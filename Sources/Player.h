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
      * @brief 주어진 위치에 배가 위치하고 있는지 체크한다. 만약 Hit 했다면 Ship 의 Hit Count 를 증가시킨다.
      만약 이미 Destroy 되었거나 올바르지 않은 위치가 주어진다면 ERROR를 반환한다. (Wrapper method of Map::HitCheck)
      * @param pos   배가 있는지 체크할 위치
      * @return      Hit 결과
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