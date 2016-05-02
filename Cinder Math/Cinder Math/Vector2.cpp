#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		template<class T>
		Vector2<T>::Vector2(T x, T y)
			: X(x), Y(y)
		{}

		template<typename T>
		Vector2<T>& Vector2<T>::YX()
		{
			return Vector2<T>(this->Y, this->X);
		}

		template<typename T>
		Vector2<T>& Vector2<T>::XY()
		{
			return Vector2<T>(this->X, this->Y);
		}

		template<typename T>
		Vector2<T>& Vector2<T>::XX()
		{
			return Vector2<T>(this->X, this->X);
		}

		template<typename T>
		Vector2<T>& Vector2<T>::YY()
		{
			return Vector2<T>(this->Y, this->Y);
		}

		namespace Vec2
		{
			template<typename T>
			float Length(Vector2<T> &v2)
			{

			}

			template<typename T>
			float LengthSquare(Vector2<T> &v2)
			{

			}

			template<typename T>
			Vector2<T>& Normalize(Vector2<T> &v2)
			{

			}


			template<typename T>
			Vector2<T>& Sum(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& Sub(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& Mul(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& Div(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}


			template<typename T>
			Vector2<T>& Sum(Vector2<T> &v2Left, T &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& Sub(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			Vector2<T>& Mul(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			Vector2<T>& Div(Vector2<T> &v2Left, T &right)
			{

			}


			template<typename T>
			Vector2<T>& Sum(T &left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& Sub(T &left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& Mul(T &left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& Div(T &left, Vector2<T> &v2Right)
			{

			}

			/////////////

			template<typename T>
			Vector2<T>& operator+(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& operator-(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& operator*(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& operator/(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}


			template<typename T>
			Vector2<T>& operator+(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			Vector2<T>& operator-(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			Vector2<T>& operator*(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			Vector2<T>& operator/(Vector2<T> &v2Left, T &right)
			{

			}


			template<typename T>
			Vector2<T>& operator+(T &left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& operator-(T &left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& operator*(T &left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			Vector2<T>& operator/(T &left, Vector2<T> &v2Right)
			{

			}

			/////////////////

			template<typename T>
			void operator+=(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			void operator-=(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			void operator*=(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}

			template<typename T>
			void operator/=(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{

			}


			template<typename T>
			void operator+=(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			void operator-=(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			void operator*=(Vector2<T> &v2Left, T &right)
			{

			}

			template<typename T>
			void operator/=(Vector2<T> &v2Left, T &right)
			{

			}
		}
	}
}