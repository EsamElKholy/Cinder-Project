#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		
		vec2f vec2f::YX()
		{
			return vec2f(this->Y, this->X);
		}

		
		vec2f vec2f::XY()
		{
			return vec2f(this->X, this->Y);
		}

		
		vec2f vec2f::XX()
		{
			return vec2f(this->X, this->X);
		}

		
		vec2f vec2f::YY()
		{
			return vec2f(this->Y, this->Y);
		}

		//////////////////////////////

		
		void vec2f::operator=(vec2f &v2Right)
		{
			this->X = v2Right.X;
			this->Y = v2Right.Y;
		}
		
		bool vec2f::operator==(vec2f &v2Right)
		{
			bool x = this->X == v2Right.X;
			bool y = this->Y == v2Right.Y;
			
			return x && y;
		}

		
		bool vec2f::operator!=(vec2f &v2Right)
		{
			bool x = this->X != v2Right.X;
			bool y = this->Y != v2Right.Y;

			return x || y;
		}

		
		float& vec2f::operator[](unsigned int index)
		{
			if (index >= 2)
			{
				index = 1;
			}

			return this->Elements[index];
		}

		/////////////////

		
		void vec2f::operator+=(vec2f &v2Right)
		{
			*this = vec2f(this->X + v2Right.X, this->Y + v2Right.Y);
		}

		
		void vec2f::operator-=(vec2f &v2Right)
		{
			*this = vec2f(this->X - v2Right.X, this->Y - v2Right.Y);
		}

		
		void vec2f::operator*=(vec2f &v2Right)
		{
			*this = vec2f(this->X * v2Right.X, this->Y * v2Right.Y);
		}

		
		void vec2f::operator/=(vec2f &v2Right)
		{
			*this = vec2f(this->X / v2Right.X, this->Y / v2Right.Y);
		}


		
		void vec2f::operator+=(float right)
		{
			*this = vec2f(this->X + right, this->Y + right);
		}

		
		void vec2f::operator-=(float right)
		{
			*this = vec2f(this->X - right, this->Y - right);
		}

		
		void vec2f::operator*=(float right)
		{
			*this = vec2f(this->X * right, this->Y * right);
		}

		
		void vec2f::operator/=(float right)
		{
			*this = vec2f(this->X / right, this->Y / right);
		}

		/////////////
		
		vec2f operator+(vec2f &v2Left, vec2f &v2Right)
		{
			vec2f res = Vec2::Sum(v2Left, v2Right);
			return res;
		}
				
		vec2f operator-(vec2f &v2Left, vec2f &v2Right)
		{
			vec2f res = Vec2::Sub(v2Left, v2Right);
			return res;
		}
				
		vec2f operator*(vec2f &v2Left, vec2f &v2Right)
		{
			vec2f res = Vec2::Mul(v2Left, v2Right);
			return res;
		}
				
		vec2f operator/(vec2f &v2Left, vec2f &v2Right)
		{
			vec2f res = Vec2::Div(v2Left, v2Right);
			return res;
		}
				
		vec2f operator+(vec2f &v2Left, float right)
		{
			vec2f res = Vec2::Sum(v2Left, right);
			return res;
		}
		
		vec2f operator-(vec2f &v2Left, float right)
		{
			vec2f res = Vec2::Sub(v2Left, right);
			return res;
		}
				
		vec2f operator*(vec2f &v2Left, float right)
		{
			vec2f res = Vec2::Mul(v2Left, right);
			return res;
		}
		
		vec2f operator/(vec2f &v2Left, float right)
		{
			vec2f res = Vec2::Div(v2Left, right);
			return res;
		}
		
		vec2f operator+(float left, vec2f &v2Right)
		{
			vec2f res = Vec2::Sum(left, v2Right);
			return res;
		}
				
		vec2f operator-(float left, vec2f &v2Right)
		{
			vec2f res = Vec2::Sub(left, v2Right);
			return res;
		}
		
		vec2f operator*(float left, vec2f &v2Right)
		{
			vec2f res = Vec2::Mul(left, v2Right);
			return res;
		}
		
		vec2f operator/(float left, vec2f &v2Right)
		{
			vec2f res = Vec2::Div(left, v2Right);
			return res;
		}

		/////////////////

		namespace Vec2
		{
			
			float Length(vec2f &v2)
			{
				float result = sqrtf((v2.X * v2.X) + (v2.Y * v2.Y));
				return result;
			}
			
			float LengthSquare(vec2f &v2)
			{
				float result = ((v2.X * v2.X) + (v2.Y * v2.Y));
				return result;
			}

			vec2f Normalize(vec2f &v2)
			{
				float length = Length(v2);
				vec2f res = vec2f((v2.X / length), (v2.Y / length));
				return res;
			}
			
			vec2f Sum(vec2f &v2Left, vec2f &v2Right)
			{
				vec2f res = vec2f(v2Right.X + v2Left.X, v2Right.Y + v2Left.Y);
				return res;
			}
			
			vec2f Sub(vec2f &v2Left, vec2f &v2Right)
			{
				vec2f res = vec2f(v2Right.X - v2Left.X, v2Right.Y - v2Left.Y);
				return res;
			}
			
			vec2f Mul(vec2f &v2Left, vec2f &v2Right)
			{
				vec2f res = vec2f(v2Right.X * v2Left.X, v2Right.Y * v2Left.Y);
				return res;
			}
			
			vec2f Div(vec2f &v2Left, vec2f &v2Right)
			{
				vec2f res = vec2f(v2Right.X / v2Left.X, v2Right.Y / v2Left.Y);
				return res;
			}
			
			vec2f Sum(vec2f &v2Left, float right)
			{
				vec2f res = vec2f(right + v2Left.X, right + v2Left.Y);
				return res;
			}
			
			vec2f Sub(vec2f &v2Left, float right)
			{
				vec2f res = vec2f(v2Left.X - right, v2Left.Y - right);
				return res;
			}
						
			vec2f Mul(vec2f &v2Left, float right)
			{
				vec2f res = vec2f(right * v2Left.X, right * v2Left.Y);
				return res;
			}
						
			vec2f Div(vec2f &v2Left, float right)
			{
				vec2f res = vec2f(v2Left.X / right, v2Left.Y / right);
				return res;
			}
			
			
			vec2f Sum(float left, vec2f &v2Right)
			{
				vec2f res = vec2f(left + v2Right.X, left + v2Right.Y);
				return res;
			}
			
			vec2f Sub(float left, vec2f &v2Right)
			{
				vec2f res = vec2f(left - v2Right.X, left - v2Right.Y);
				return res;
			}

			
			vec2f Mul(float left, vec2f &v2Right)
			{
				vec2f res = vec2f(left * v2Right.X, left * v2Right.Y);
				return res;
			}
						
			vec2f Div(float left, vec2f &v2Right)
			{
				vec2f res = vec2f(left / v2Right.X, left / v2Right.Y);
				return res;
			}	
			
			vec2f Translate(vec2f &point, vec2f &direction)
			{
				vec2f result = Mat4::Translation(vec3f(direction)) * point;

				return result;
			}
			
			vec2f Rotate(vec2f &point, vec2f &angle)
			{
				vec2f result = Mat4::Rotation(vec3f(angle)) * point;

				return result;
			}
			
			vec2f Scale(vec2f &point, vec2f &value)
			{
				vec2f result = Mat4::Scale(vec3f(value)) * point;

				return result;
			}
		}
	}
}
