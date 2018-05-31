// @Author Yang Kyowon(yangkyowon@kookmin.ac.kr)
#pragma once
#include "UserInterface.h"

namespace BattleShip
{
   class GameEndUI : public UserInterface
   {
   public:
      GameEndUI( const std::string& name,
                 const IntVec2& position,
                 unsigned int width, unsigned int height ) :
         UserInterface( name,
                        position,
                        width, height )
      {
      }

   protected:
      virtual void DrawImpl( ) override;

   };
}
