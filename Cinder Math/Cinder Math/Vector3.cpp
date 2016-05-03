#ifndef VECTOR3_CPP
#define VECTOR3_CPP

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
		Vector2<T> Vector3<T>::XX()
		{
			return Vector2<T>(this->X, this->X);
		}

		template<class T>
		Vector2<T> Vector3<T>::XY()
		{
			return Vector2<T>(this->X, this->Y);
		}

		template<class T>
		Vector2<T> Vector3<T>::XZ()
		{
			return Vector2<T>(this->X, this->Z);
		}

		//////////////////////

		template<class T>
		Vector2<T> Vector3<T>::YX()
		{
			return Vector2<T>(this->Y, this->X);
		}

		template<class T>
		Vector2<T> Vector3<T>::YY()
		{
			return Vector2<T>(this->Y, this->Y);
		}

		template<class T>
		Vector2<T> Vector3<T>::YZ()
		{
			return Vector2<T>(this->Y, this->Z);
		}

		//////////////////////

		template<class T>
		Vector2<T> Vector3<T>::ZX()
		{
			return Vector2<T>(this->Z, this->X);
		}

		template<class T>
		Vector2<T> Vector3<T>::ZY()
		{
			return Vector2<T>(this->Z, this->Y);
		}

		template<class T>
		Vector2<T> Vector3<T>::ZZ()
		{
			return Vector2<T>(this->Z, this->Z);
		}

		//////////////////////

		template<class T>
		Vector3<T> Vector3<T>::XXX()
		{
			return Vector3<T>(this->X, this->X, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::XXY()
		{
			return Vector3<T>(this->X, this->X, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::XXZ()
		{
			return Vector3<T>(this->X, this->X, this->Z);
		}

		template<class T>
		Vector3<T> Vector3<T>::XYX()
		{
			return Vector3<T>(this->X, this->Y, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::XYY()
		{
			return Vector3<T>(this->X, this->Y, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::XYZ()
		{
			return Vector3<T>(this->X, this->Y, this->Z);
		}

		template<class T>
		Vector3<T> Vector3<T>::XZX()
		{
			return Vector3<T>(this->X, this->Z, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::XZY()
		{
			return Vector3<T>(this->X, this->Z, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::XZZ()
		{
			return Vector3<T>(this->X, this->Z, this->Z);
		}

		//////////////////////

		template<class T>
		Vector3<T> Vector3<T>::YXX()
		{
			return Vector3<T>(this->Y, this->X, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::YXY()
		{
			return Vector3<T>(this->Y, this->X, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::YXZ()
		{
			return Vector3<T>(this->Y, this->X, this->Z);
		}

		template<class T>
		Vector3<T> Vector3<T>::YYX()
		{
			return Vector3<T>(this->Y, this->Y, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::YYY()
		{
			return Vector3<T>(this->Y, this->Y, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::YYZ()
		{
			return Vector3<T>(this->Y, this->Y, this->Z);
		}

		template<class T>
		Vector3<T> Vector3<T>::YZX()
		{
			return Vector3<T>(this->Y, this->Z, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::YZY()
		{
			return Vector3<T>(this->Y, this->Z, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::YZZ()
		{
			return Vector3<T>(this->Y, this->Z, this->Z);
		}

		//////////////////////

		template<class T>
		Vector3<T> Vector3<T>::ZXX()
		{
			return Vector3<T>(this->Z, this->X, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZXY()
		{
			return Vector3<T>(this->Z, this->X, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZXZ()
		{
			return Vector3<T>(this->Z, this->X, this->Z);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZYX()
		{
			return Vector3<T>(this->Z, this->Y, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZYY()
		{
			return Vector3<T>(this->Z, this->Y, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZYZ()
		{
			return Vector3<T>(this->Z, this->Y, this->Z);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZZX()
		{
			return Vector3<T>(this->Z, this->Z, this->X);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZZY()
		{
			return Vector3<T>(this->Z, this->Z, this->Y);
		}

		template<class T>
		Vector3<T> Vector3<T>::ZZZ()
		{
			return Vector3<T>(this->Z, this->Z, this->Z);
		}

		//////////////////////////////////

		template<class T>
		void Vector3<T>::operator+=(Vector3<T> &v3Right)
		{
			*this = Vector3<T>(this->X + v3Right.X, this->Y + v3Right.Y, this->Z + v3Right.Z);
		}

		template<class T>
		void Vector3<T>::operator-=(Vector3<T> &v3Right)
		{
			*this = Vector3<T>(this->X - v3Right.X, this->Y - v3Right.Y, this->Z - v3Right.Z);
		}

		template<class T>
		void Vector3<T>::operator*=(Vector3<T> &v3Right)
		{
			*this = Vector3<T>(this->X * v3Right.X, this->Y * v3Right.Y, this->Z * v3Right.Z);
		}

		template<class T>
		void Vector3<T>::operator/=(Vector3<T> &v3Right)
		{
			*this = Vector3<T>(this->X / v3Right.X, this->Y / v3Right.Y, this->Z / v3Right.Z);
		}


		template<class T>
		void Vector3<T>::operator+=(T right)
		{
			*this = Vector3<T>(this->X + right, this->Y + right, this->Z + right);
		}

		template<class T>
		void Vector3<T>::operator-=(T right)
		{
			*this = Vector3<T>(this->X - right, this->Y - right, this->Z - right);
		}

		template<class T>
		void Vector3<T>::operator*=(T right)
		{
			*this = Vector3<T>(this->X * right, this->Y * right, this->Z * right);
		}

		template<class T>
		void Vector3<T>::operator/=(T right)
		{
			*this = Vector3<T>(this->X / right, this->Y / right, this->Z / right);
		}

		//////////////////////////////////

		template<class T>
		void Vector3<T>::operator=(Vector3<T> &v3Right)
		{
			this->X = v3Right.X;
			this->Y = v3Right.Y;
			this->Z = v3Right.Z;
		}

		template<class T>
		bool Vector3<T>::operator==(Vector3<T> &v3Right)
		{
			bool x = this->X == v3Right.X;
			bool y = this->Y == v3Right.Y;
			bool z = this->Z == v3Right.Z;

			return x && y && z;
		}

		template<class T>
		bool Vector3<T>::operator!=(Vector3<T> &v3Right)
		{
			bool x = this->X != v3Right.X;
			bool y = this->Y != v3Right.Y;
			bool z = this->Z != v3Right.Z;

			return x || y || z;
		}

		template<class T>
		T Vector3<T>::operator[](unsigned int index)
		{
			if (index >= 3)
			{
				index = 2;
			}

			return this->Elements[index];
		}

		///////////////////////////////////

		template<typename T>
		Vector3<T> operator+(Vector3<T> &v3Left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Sum(v3Left, v3Right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator-(Vector3<T> &v3Left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Sub(v3Left, v3Right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator*(Vector3<T> &v3Left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Mul(v3Left, v3Right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator/(Vector3<T> &v3Left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Div(v3Left, v3Right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator+(Vector3<T> &v3Left, T right)
		{
			v3Left = Vec3::Sum(v3Left, right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator-(Vector3<T> &v3Left, T right)
		{
			v3Left = Vec3::Sub(v3Left, right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator*(Vector3<T> &v3Left, T right)
		{
			v3Left = Vec3::Mul(v3Left, right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator/(Vector3<T> &v3Left, T right)
		{
			v3Left = Vec3::Div(v3Left, right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator+(T left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Sum(left, v3Right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator-(T left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Sub(left, v3Right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator*(T left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Mul(left, v3Right);
			return v3Left;
		}

		template<typename T>
		Vector3<T> operator/(T left, Vector3<T> &v3Right)
		{
			v3Left = Vec3::Div(left, v3Right);
			return v3Left;
		}

		///////////////////////////////////

		namespace Vec3
		{
			template<typename T>
			float Length(Vector3<T> &v3)
			{
				float result = sqrtf((v3.X * v3.X) + (v3.Y * v3.Y) + (v3.Z * v3.Z));
				return result;
			}

			template<typename T>
			float LengthSquare(Vector3<T> &v3)
			{
				float result = ((v3.X * v3.X) + (v3.Y * v3.Y) + (v3.Z * v3.Z));
				return result;
			}

			template<typename T>
			Vector3<T> Normalize(Vector3<T> &v3)
			{
				float length = Length(v3);
				v3 = Vector3<T>((v3.X / length), (v3.Y / length), (v3.Z / length));
				return v3;
			}

			template<typename T>
			Vector3<T> Sum(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(v3Left.X + v3Right.X, v3Left.Y + v3Right.Y, v3Left.Z + v3Right.Z);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Sub(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(v3Left.X - v3Right.X, v3Left.Y - v3Right.Y, v3Left.Z - v3Right.Z);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Mul(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(v3Left.X * v3Right.X, v3Left.Y * v3Right.Y, v3Left.Z * v3Right.Z);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Div(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(v3Left.X / v3Right.X, v3Left.Y / v3Right.Y, v3Left.Z / v3Right.Z);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Sum(Vector3<T> &v3Left, T right)
			{
				v3Left = Vector3<T>(v3Left.X + right, v3Left.Y + right, v3Left.Z + right);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Sub(Vector3<T> &v3Left, T right)
			{
				v3Left = Vector3<T>(v3Left.X - right, v3Left.Y - right, v3Left.Z - right);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Mul(Vector3<T> &v3Left, T right)
			{
				v3Left = Vector3<T>(v3Left.X * right, v3Left.Y * right, v3Left.Z * right);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Div(Vector3<T> &v3Left, T right)
			{
				v3Left = Vector3<T>(v3Left.X / right, v3Left.Y / right, v3Left.Z / right);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Sum(T left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(left + v3Right.X, left + v3Right.Y, left + v3Right.Z);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Sub(T left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(left - v3Right.X, left - v3Right.Y, left - v3Right.Z);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Mul(T left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(left * v3Right.X, left * v3Right.Y, left * v3Right.Z);
				return v3Left;
			}

			template<typename T>
			Vector3<T> Div(T left, Vector3<T> &v3Right)
			{
				v3Left = Vector3<T>(left / v3Right.X, left / v3Right.Y, left / v3Right.Z);
				return v3Left;
			}		

			/////////////////////////////

			template<typename T>
			float Dot(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{
				float x = v3Left.X * v3Right.X;
				float y = v3Left.Y * v3Right.Y;
				float z = v3Left.Z * v3Right.Z;

				return (x + y + z);
			}

			template<typename T>
			Vector3<T> Cross(Vector3<T> &v3Left, Vector3<T> &v3Right)
			{
				T x = (v3Left.Y * v3Right.Z) - (v3Left.Z * v3Right.Y);
				T y = (v3Left.X * v3Right.Z) - (v3Left.Z * v3Right.X);
				T z = (v3Left.X * v3Right.Y) - (v3Left.Y * v3Right.X);

				return Vector3<T>(x, y, z);
			}

			template<typename T>
			Vector3<T> Translate(Vector3<T> &point, Vector3<T> &direction)
			{
				Vector3<T> result = Mat4::Translation(direction) * point;

				return result;
			}

			template<typename T>
			Vector3<T> Rotate(Vector3<T> &point, Vector3<T> &angle)
			{
				Vector3<T> result = Mat4::Rotation(angle) * point;

				return result;
			}

			template<typename T>
			Vector3<T> Scale(Vector3<T> &point, Vector3<T> &value)
			{
				Vector3<T> result = Mat4::Scale(value) * point;

				return result;
			}
		}
	}
}

#endif