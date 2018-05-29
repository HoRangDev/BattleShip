#pragma once
#include "GameInstance.h"

namespace BattleShip
{
   class ShipMap;
   class RandomGameInstance : public GameInstance
   {
   public:
      RandomGameInstance( int width, int height );

      virtual void Init( ) override;
      virtual void Update( ) override;
      virtual void Render( ) override;

   private:
      ShipMap* m_defenderMap;

   };
}