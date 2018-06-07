#pragma once
#include "GameInstance.h"

namespace BattleShip
{
   enum class FindStage
   {
      RandomPick,
      SearchDir,
      Search,
      SearchOpposite
   };

   class RandGameInst : public GameInstance
   {
   public:
      RandGameInst( int width, int height, int repeat );

      void Reset( );

   protected:
      virtual void Init( ) override;
      virtual void Update( ) override;
      virtual void Render( ) override;

      IntVec2 FindNext( );

   private:
      /* Dependency **/
      class HitMap*  m_attackerMap;
      class ShipMap* m_defenderMap;

      int m_maxRepeatCount;
      int m_repeatCount;
      int m_totalTurn;

      FindStage m_findStage;
      IntVec2 m_findOrigin;
      IntVec2 m_curFindPos;
      Direction m_findDir;

      /* UI **/
      class MapUI*      m_attackerMapUI;
      class MapUI*      m_defenderMapUI;
      class StatUI*     m_statUI;
      class AIStatUI*   m_aiStatUI;

   };
}