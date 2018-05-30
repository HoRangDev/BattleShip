#pragma once
#include "GameInstance.h"

namespace BattleShip
{
   class ShipMap;
   class MapUI;
   class SVGameInstance : public GameInstance
   {
   public:
      SVGameInstance( int width, int height );

      virtual void Init( ) override;
      virtual void Update( ) override;
      virtual void Render( ) override;

   private:
      /* Dependency **/
      ShipMap* m_defenderMap;

      /* UI **/
      MapUI*   m_attackerMapUI;
      MapUI*   m_defenderMapUI;

   };
}