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
         UserInterface( name, position,
                        width, height )
      {
      }

      void SetLatestSelection( int row, int col );

   protected:
      virtual void DrawImpl( ) override;

   private:
      std::string m_selectionMsg;

   };
}
