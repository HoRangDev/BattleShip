#pragma once
#include "GameInstance.h"

namespace BattleShip
{
   class HitMap;
   class ShipMap;
   class MapUI;
   class StatUI;
   class InputUI;
   class SVGameInstance : public GameInstance
   {
   public:
      SVGameInstance( int width, int height );

      virtual void Init( ) override;
      virtual void Update( ) override;
      virtual void Render( ) override;

   private:
      /* Dependency **/
      HitMap*  m_attackerMap;
      ShipMap* m_defenderMap;

      /* UI **/
      MapUI*   m_attackerMapUI;
      MapUI*   m_defenderMapUI;
      StatUI*  m_statUI;
      InputUI* m_inputUI;

   };
}