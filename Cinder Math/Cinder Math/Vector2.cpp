#ifndef VECTOR2_CPP
#define VECTOR2_CPP

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
		Vector2<T> Vector2<T>::YX()
		{
			return Vector2<T>(this->Y, this->X);
		}

		template<class T>
		Vector2<T> Vector2<T>::XY()
		{
			return Vector2<T>(this->X, this->Y);
		}

		template<class T>
		Vector2<T> Vector2<T>::XX()
		{
			return Vector2<T>(this->X, this->X);
		}

		template<class T>
		Vector2<T> Vector2<T>::YY()
		{
			return Vector2<T>(this->Y, this->Y);
		}

		//////////////////////////////

		template<class T>
		void Vector2<T>::operator=(Vector2<T> &v2Right)
		{
			this->X = v2Right.X;
			this->Y = v2Right.Y;
		}
		
		template<class T>
		bool Vector2<T>::operator==(Vector2<T> &v2Right)
		{
			bool x = this->X == v2Right.X;
			bool y = this->Y == v2Right.Y;
			
			return x && y;
		}

		template<class T>
		bool Vector2<T>::operator!=(Vector2<T> &v2Right)
		{
			bool x = this->X != v2Right.X;
			bool y = this->Y != v2Right.Y;

			return x || y;
		}

		template<class T>
		T Vector2<T>::operator[](unsigned int index)
		{
			if (index >= 2)
			{
				index = 1;
			}

			return this->Elements[index];
		}

		/////////////////

		template<class T>
		void Vector2<T>::operator+=(Vector2<T> &v2Right)
		{
			*this = Vector2<T>(this->X + v2Left.X, this->Y + v2Right.Y);
		}

		template<class T>
		void Vector2<T>::operator-=(Vector2<T> &v2Right)
		{
			*this = Vector2<T>(this->X - v2Left.X, this->Y - v2Right.Y);
		}

		template<class T>
		void Vector2<T>::operator*=(Vector2<T> &v2Right)
		{
			*this = Vector2<T>(this->X * v2Left.X, this->Y * v2Right.Y);
		}

		template<class T>
		void Vector2<T>::operator/=(Vector2<T> &v2Right)
		{
			*this = Vector2<T>(this->X / v2Left.X, this->Y / v2Right.Y);
		}


		template<class T>
		void Vector2<T>::operator+=(T right)
		{
			*this = Vector2<T>(this->X + right, this->Y + right);
		}

		template<class T>
		void Vector2<T>::operator-=(T right)
		{
			*this = Vector2<T>(this->X - right, this->Y - right);
		}

		template<class T>
		void Vector2<T>::operator*=(T right)
		{
			*this = Vector2<T>(this->X * right, this->Y * right);
		}

		template<class T>
		void Vector2<T>::operator/=(T right)
		{
			*this = Vector2<T>(this->X / right, this->Y / right);
		}

		/////////////

		template<typename T>
		Vector2<T> operator+(Vector2<T> &v2Left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Sum(v2Left, v2Right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator-(Vector2<T> &v2Left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Sub(v2Left, v2Right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator*(Vector2<T> &v2Left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Mul(v2Left, v2Right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator/(Vector2<T> &v2Left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Div(v2Left, v2Right);
			return v2Left;
		}


		template<typename T>
		Vector2<T> operator+(Vector2<T> &v2Left, T right)
		{
			v2Left = Vec2::Sum(v2Left, right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator-(Vector2<T> &v2Left, T right)
		{
			v2Left = Vec2::Sub(v2Left, right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator*(Vector2<T> &v2Left, T right)
		{
			v2Left = Vec2::Mul(v2Left, right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator/(Vector2<T> &v2Left, T right)
		{
			v2Left = Vec2::Div(v2Left, right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator+(T left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Sum(left, v2Right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator-(T left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Sub(left, v2Right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator*(T left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Mul(left, v2Right);
			return v2Left;
		}

		template<typename T>
		Vector2<T> operator/(T left, Vector2<T> &v2Right)
		{
			v2Left = Vec2::Div(left, v2Right);
			return v2Left;
		}

		/////////////////

		namespace Vec2
		{
			template<typename T>
			float Length(Vector2<T> &v2)
			{
				float result = sqrtf((v2.X * v2.X) + (v2.Y * v2.Y));
				return result;
			}

			template<typename T>
			float LengthSquare(Vector2<T> &v2)
			{
				float result = ((v2.X * v2.X) + (v2.Y * v2.Y));
				return result;
			}

			template<typename T>
			Vector2<T> Normalize(Vector2<T> &v2)
			{
				float length = Length(v2);
				v2 = Vector2<T>((v2.X / length), (v2.Y / length));
				return v2;
			}


			template<typename T>
			Vector2<T> Sum(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(v2Right.X + v2Left.X, v2Right.Y + v2Left.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Sub(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(v2Right.X - v2Left.X, v2Right.Y - v2Left.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Mul(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(v2Right.X * v2Left.X, v2Right.Y * v2Left.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Div(Vector2<T> &v2Left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(v2Right.X / v2Left.X, v2Right.Y / v2Left.Y);
				return v2Left;
			}


			template<typename T>
			Vector2<T> Sum(Vector2<T> &v2Left, T right)
			{
				v2Left = Vector2<T>(right + v2Left.X, right + v2Left.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Sub(Vector2<T> &v2Left, T right)
			{
				v2Left = Vector2<T>(v2Left.X - right, v2Left.Y - right);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Mul(Vector2<T> &v2Left, T right)
			{
				v2Left = Vector2<T>(right * v2Left.X, right * v2Left.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Div(Vector2<T> &v2Left, T right)
			{
				v2Left = Vector2<T>(v2Left.X / right, v2Left.Y / right);
				return v2Left;
			}


			template<typename T>
			Vector2<T> Sum(T left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(left + v2Right.X, left + v2Right.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Sub(T left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(left - v2Right.X, left - v2Right.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Mul(T left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(left * v2Right.X, left * v2Right.Y);
				return v2Left;
			}

			template<typename T>
			Vector2<T> Div(T left, Vector2<T> &v2Right)
			{
				v2Left = Vector2<T>(left / v2Right.X, left / v2Right.Y);
				return v2Left;
			}			

			template<typename T>
			Vector2<T> Translate(Vector2<T> &point, Vector2<T> &direction)
			{
				Vector2<T> result = Mat4::Translation(direction) * point;

				return result;
			}

			template<typename T>
			Vector2<T> Rotate(Vector2<T> &point, Vector2<T> &angle)
			{
				Vector2<T> result = Mat4::Rotation(angle) * point;

				return result;
			}

			template<typename T>
			Vector2<T> Scale(Vector2<T> &point, Vector2<T> &value)
			{
				Vector2<T> result = Mat4::Scale(value) * point;

				return result;
			}
		}
	}
}

#endif