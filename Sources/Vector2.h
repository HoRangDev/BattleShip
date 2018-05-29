#pragma once

namespace BattleShip
{
   template <typename Ty>
   struct Vector2
   {
   public:
      Vector2( Ty xx = Ty(), Ty yy = Ty() ) :
         x( xx ),
         y( yy )
      {
      }

      Vector2 operator+( const Vector2& rhs ) const
      {
         return Vector2( x + rhs.x, y + rhs.y );
      }

      Vector2 operator+=( const Vector2& rhs )
      {
         x += rhs.x;
         y += rhs.y;
         return ( *this );
      }

      Vector2 operator-( const Vector2& rhs ) const
      {
         return Vector2( x - rhs.x, y - rhs.y );
      }

      Vector2& operator-=( const Vector2& rhs )
      {
         x -= rhs.x;
         y -= rhs.y;
         return ( *this );
      }

      inline bool operator==( const Vector2& rhs ) const
      {
         return ( x == rhs.x ) && ( y == rhs.y );
      }

      bool operator!=( const Vector2& rhs ) const
      {
         return !( ( *this ) == rhs );
      }

   public:
      Ty x;
      Ty y;

   };
}
