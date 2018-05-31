#pragma once
#include "UserInterface.h"

namespace BattleShip
{
   class Map;
   class InputUI : public UserInterface
   {
   public:
      InputUI( const std::string& name,
               const IntVec2& position,
               unsigned int width, unsigned int height,
               Map* attackerMap) : 
         m_bIsAbleToUseInput( false ),
         m_inputMessageStr( "Input(ex. A3): " ),
         UserInterface( name, position,
                        width, height )
      {
      }

      void Update( );
      IntVec2 GetInput( ) const { return m_input; }
      bool IsAbleToUseInput( ) const { return m_bIsAbleToUseInput; }

   protected:
      virtual void DrawImpl( ) override;

   private:
      bool  m_bIsAbleToUseInput;
      const std::string m_inputMessageStr;
      IntVec2  m_input;

      Map* m_attackerMap;

   };
}