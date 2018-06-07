// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once
#include "UserInterface.h"

namespace BattleShip
{
   class ShipMap;
   class StatUI : public UserInterface
   {
   public:
      StatUI(
         const std::string& name,
         const IntVec2& position,
         unsigned int width, unsigned int height ) :
         m_turn( 0 ),
         UserInterface( name, position,
                        width, height )
      {
      }

      void SetShipMap( const ShipMap* map )
      {
         m_shipMap = map;
      }

      void SetTurn( int turn )
      {
         m_turn = turn;
      }

   protected:
      virtual void DrawImpl( ) override;

   private:
      const ShipMap* m_shipMap;
      int m_turn;

   };
}