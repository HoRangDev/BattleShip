#pragma once
#include "GameInstance.h"

namespace BattleShip
{
   class RandGameInst : public GameInstance
   {
   public:
      RandGameInst( int width, int height );

      void Reset( );

   protected:
      virtual void Init( ) override;
      virtual void Update( ) override;
      virtual void Render( ) override;

   private:
      /* Dependency **/
      class HitMap*  m_attackerMap;
      class ShipMap* m_defenderMap;

      /* UI **/
      class MapUI*   m_attackerMapUI;
      class MapUI*   m_defenderMapUI;
      class StatUI*  m_statUI;

   };
}