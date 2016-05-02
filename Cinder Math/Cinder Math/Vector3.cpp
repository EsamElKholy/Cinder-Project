#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		template<class T>
		Vector3<T>::Vector3(T x, T y, T z)
			: X(x), Y(y), Z(z)
		{}

		template<class T>
		Vector3<T>::Vector3(Vector2<T> &vec2, T z)
			: X(vec2.X), Y(vec2.Y), Z(z)
		{}

		template<class T>
		Vector3<T>::Vector3(T x, Vector2<T> &vec2)
			: X(x), Y(vec2.Z), Z(vec2.Y)
		{}

		template<class T>
		Vector3<T>::Vector3(Vector2<T> &vec2)
			: X(vec2.X), Y(vec2.Y), Z(T(0))
		{}

		//////////////////////					

		template<class T>
		Vector2<T>& Vector3<T>::XX()
		{
			return Vector2<T>(this->X, this->X);
		}

		template<class T>
		Vector2<T>& Vector3<T>::XY()
		{
			return Vector2<T>(this->X, this->Y);
		}

		template<class T>
		Vector2<T>& Vector3<T>::XZ()
		{
			return Vector2<T>(this->X, this->Z);
		}

		//////////////////////

		template<class T>
		Vector2<T>& Vector3<T>::YX()
		{
			return Vector2<T>(this->Y, this->X);
		}

		template<class T>
		Vector2<T>& Vector3<T>::YY()
		{
			return Vector2<T>(this->Y, this->Y);
		}

		template<class T>
		Vector2<T>& Vector3<T>::YZ()
		{
			return Vector2<T>(this->Y, this->Z);
		}

		//////////////////////

		template<class T>
		Vector2<T>& Vector3<T>::ZX()
		{
			return Vector2<T>(this->Z, this->X);
		}

		template<class T>
		Vector2<T>& Vector3<T>::ZY()
		{
			return Vector2<T>(this->Z, this->Y);
		}

		template<class T>
		Vector2<T>& Vector3<T>::ZZ()
		{
			return Vector2<T>(this->Z, this->Z);
		}

		//////////////////////

		template<class T>
		Vector3<T>& Vector3<T>::XXX()
		{
			return Vector3<T>(this->X, this->X, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XXY()
		{
			return Vector3<T>(this->X, this->X, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XXZ()
		{
			return Vector3<T>(this->X, this->X, this->Z);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XYX()
		{
			return Vector3<T>(this->X, this->Y, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XYY()
		{
			return Vector3<T>(this->X, this->Y, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XYZ()
		{
			return Vector3<T>(this->X, this->Y, this->Z);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XZX()
		{
			return Vector3<T>(this->X, this->Z, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XZY()
		{
			return Vector3<T>(this->X, this->Z, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::XZZ()
		{
			return Vector3<T>(this->X, this->Z, this->Z);
		}

		//////////////////////

		template<class T>
		Vector3<T>& Vector3<T>::YXX()
		{
			return Vector3<T>(this->Y, this->X, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YXY()
		{
			return Vector3<T>(this->Y, this->X, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YXZ()
		{
			return Vector3<T>(this->Y, this->X, this->Z);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YYX()
		{
			return Vector3<T>(this->Y, this->Y, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YYY()
		{
			return Vector3<T>(this->Y, this->Y, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YYZ()
		{
			return Vector3<T>(this->Y, this->Y, this->Z);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YZX()
		{
			return Vector3<T>(this->Y, this->Z, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YZY()
		{
			return Vector3<T>(this->Y, this->Z, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::YZZ()
		{
			return Vector3<T>(this->Y, this->Z, this->Z);
		}

		//////////////////////

		template<class T>
		Vector3<T>& Vector3<T>::ZXX()
		{
			return Vector3<T>(this->Z, this->X, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZXY()
		{
			return Vector3<T>(this->Z, this->X, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZXZ()
		{
			return Vector3<T>(this->Z, this->X, this->Z);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZYX()
		{
			return Vector3<T>(this->Z, this->Y, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZYY()
		{
			return Vector3<T>(this->Z, this->Y, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZYZ()
		{
			return Vector3<T>(this->Z, this->Y, this->Z);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZZX()
		{
			return Vector3<T>(this->Z, this->Z, this->X);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZZY()
		{
			return Vector3<T>(this->Z, this->Z, this->Y);
		}

		template<class T>
		Vector3<T>& Vector3<T>::ZZZ()
		{
			return Vector3<T>(this->Z, this->Z, this->Z);
		}

		namespace Vec3
		{
			template<typename T>
			float Length(Vector3<T> &v3)
			{

			}

			template<typename T>
			float LengthSquare(Vector3<T> &v3)
			{

			}

			template<typename T>
			Vector3<T>& Normalize(Vector3<T> &v3)
			{

			}

			template<typename T>
			Vector3<T>& Sum(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& Sub(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& Mul(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& Div(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}


			template<typename T>
			Vector3<T>& Sum(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			Vector3<T>& Sub(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			Vector3<T>& Mul(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			Vector3<T>& Div(Vector3<T> &v3Left, T &right)
			{

			}


			template<typename T>
			Vector3<T>& Sum(T &left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& Sub(T &left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& Mul(T &left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& Div(T &left, Vector3<T> &v3Right)
			{

			}

			/////////////

			template<typename T>
			Vector3<T>& operator+(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& operator-(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& operator*(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& operator/(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}


			template<typename T>
			Vector3<T>& operator+(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			Vector3<T>& operator-(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			Vector3<T>& operator*(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			Vector3<T>& operator/(Vector3<T> &v3Left, T &right)
			{

			}


			template<typename T>
			Vector3<T>& operator+(T &left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& operator-(T &left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& operator*(T &left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			Vector3<T>& operator/(T &left, Vector3<T> &v3Right)
			{

			}

			/////////////////

			template<typename T>
			void operator+=(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			void operator-=(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			void operator*=(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}

			template<typename T>
			void operator/=(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{

			}


			template<typename T>
			void operator+=(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			void operator-=(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			void operator*=(Vector3<T> &v3Left, T &right)
			{

			}

			template<typename T>
			void operator/=(Vector3<T> &v3Left, T &right)
			{

			}
		}
	}
}