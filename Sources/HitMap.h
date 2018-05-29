#pragma once
#include "Map.h"

namespace BattleShip
{
   class HitMap : public Map
   {
   public:
      HitMap( int width, int height );
      virtual ~HitMap( );

      void CheckAs( const IntVec2& pos, HitResultType type );

      virtual char GetCharFrom( const IntVec2& pos ) const override;
      virtual void Reset( ) override;

   private:
      HitResultType**   m_hitMap;

   };
}