#pragma once
#include "UserInterface.h"

namespace BattleShip
{
   class ShipMap;
   class HitMap;
   class Map;
   class MapUI : public UserInterface
   {
   public:
      MapUI(
         const std::string& name,
         const IntVec2& position,
         unsigned int width, unsigned int height,
         const Map* map ) :
         m_map( map ),
         UserInterface( name, position, width, height )
      {
      }

      void SetSpace( const IntVec2& space ) { m_space = space; }
      IntVec2 GetSpace( ) const { return m_space; }

   protected:
      virtual void DrawImpl( ) override;

   private:
      const Map* m_map;
      IntVec2 m_space;

   };
}