#pragma once
#include "UserInterface.h"

namespace BattleShip
{
   class Ship;
   class StatUI : public UserInterface
   {
   public:
      StatUI(
         const std::string& name,
         const IntVec2& position,
         unsigned int width, unsigned int height,
         const std::vector<Ship*>& ships ) :
         m_ships( ships ),
         m_turn( 0 ),
         UserInterface( name, position,
                        width, height )
      {
      }

      void SetShipList( const std::vector<Ship*>& ships )
      {
         m_ships = ships;
      }

      void SetTurn( int turn )
      {

      }

   protected:
      virtual void DrawImpl( ) override;

   private:
      std::vector<Ship*>  m_ships;
      int m_turn;

   };
}