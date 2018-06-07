#pragma once
#include "UserInterface.h"

namespace BattleShip
{
   class AIStatUI : public UserInterface
   {
   public:
      AIStatUI( const std::string& name,
                const IntVec2& position,
                unsigned int width, unsigned int height ) :
         m_latestRow( 0 ), m_latestCol( 0 ),
         m_turnCount( 0 ), m_totalTurnCount( 0 ),
         m_repeatCount( 0 ),
         UserInterface( name, position,
                        width, height )
      {
      }

      void SetLatestSelection( int row, int col );
      void SetRoundValue( int turnCount, int totalTurnCount, int repeat );

   protected:
      virtual void DrawImpl( ) override;

   private:
      std::string m_selectionMsg;
      int m_latestRow;
      int m_latestCol;
      int m_turnCount;
      int m_totalTurnCount;
      int m_repeatCount;

   };
}
