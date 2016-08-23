#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		vec2f vec3f::XX()
		{
			return vec2f(this->X, this->X);
		}

		vec2f vec3f::XY()
		{
			return vec2f(this->X, this->Y);
		}

		vec2f vec3f::XZ()
		{
			return vec2f(this->X, this->Z);
		}

		//////////////////////

		vec2f vec3f::YX()
		{
			return vec2f(this->Y, this->X);
		}

		vec2f vec3f::YY()
		{
			return vec2f(this->Y, this->Y);
		}

		vec2f vec3f::YZ()
		{
			return vec2f(this->Y, this->Z);
		}

		//////////////////////

		vec2f vec3f::ZX()
		{
			return vec2f(this->Z, this->X);
		}

		vec2f vec3f::ZY()
		{
			return vec2f(this->Z, this->Y);
		}

		vec2f vec3f::ZZ()
		{
			return vec2f(this->Z, this->Z);
		}

		//////////////////////

		vec3f vec3f::XXX()
		{
			return vec3f(this->X, this->X, this->X);
		}

		vec3f vec3f::XXY()
		{
			return vec3f(this->X, this->X, this->Y);
		}

		vec3f vec3f::XXZ()
		{
			return vec3f(this->X, this->X, this->Z);
		}

		vec3f vec3f::XYX()
		{
			return vec3f(this->X, this->Y, this->X);
		}

		vec3f vec3f::XYY()
		{
			return vec3f(this->X, this->Y, this->Y);
		}

		vec3f vec3f::XYZ()
		{
			return vec3f(this->X, this->Y, this->Z);
		}

		vec3f vec3f::XZX()
		{
			return vec3f(this->X, this->Z, this->X);
		}

		vec3f vec3f::XZY()
		{
			return vec3f(this->X, this->Z, this->Y);
		}

		vec3f vec3f::XZZ()
		{
			return vec3f(this->X, this->Z, this->Z);
		}

		//////////////////////

		vec3f vec3f::YXX()
		{
			return vec3f(this->Y, this->X, this->X);
		}

		vec3f vec3f::YXY()
		{
			return vec3f(this->Y, this->X, this->Y);
		}

		vec3f vec3f::YXZ()
		{
			return vec3f(this->Y, this->X, this->Z);
		}

		vec3f vec3f::YYX()
		{
			return vec3f(this->Y, this->Y, this->X);
		}

		vec3f vec3f::YYY()
		{
			return vec3f(this->Y, this->Y, this->Y);
		}

		vec3f vec3f::YYZ()
		{
			return vec3f(this->Y, this->Y, this->Z);
		}

		vec3f vec3f::YZX()
		{
			return vec3f(this->Y, this->Z, this->X);
		}

		vec3f vec3f::YZY()
		{
			return vec3f(this->Y, this->Z, this->Y);
		}

		vec3f vec3f::YZZ()
		{
			return vec3f(this->Y, this->Z, this->Z);
		}

		//////////////////////

		vec3f vec3f::ZXX()
		{
			return vec3f(this->Z, this->X, this->X);
		}

		vec3f vec3f::ZXY()
		{
			return vec3f(this->Z, this->X, this->Y);
		}

		vec3f vec3f::ZXZ()
		{
			return vec3f(this->Z, this->X, this->Z);
		}

		vec3f vec3f::ZYX()
		{
			return vec3f(this->Z, this->Y, this->X);
		}

		vec3f vec3f::ZYY()
		{
			return vec3f(this->Z, this->Y, this->Y);
		}

		vec3f vec3f::ZYZ()
		{
			return vec3f(this->Z, this->Y, this->Z);
		}

		vec3f vec3f::ZZX()
		{
			return vec3f(this->Z, this->Z, this->X);
		}

		vec3f vec3f::ZZY()
		{
			return vec3f(this->Z, this->Z, this->Y);
		}

		vec3f vec3f::ZZZ()
		{
			return vec3f(this->Z, this->Z, this->Z);
		}

		//////////////////////////////////

		void vec3f::operator+=(vec3f &v3Right)
		{
			*this = vec3f(this->X + v3Right.X, this->Y + v3Right.Y, this->Z + v3Right.Z);
		}

		void vec3f::operator-=(vec3f &v3Right)
		{
			*this = vec3f(this->X - v3Right.X, this->Y - v3Right.Y, this->Z - v3Right.Z);
		}

		void vec3f::operator*=(vec3f &v3Right)
		{
			*this = vec3f(this->X * v3Right.X, this->Y * v3Right.Y, this->Z * v3Right.Z);
		}

		void vec3f::operator/=(vec3f &v3Right)
		{
			*this = vec3f(this->X / v3Right.X, this->Y / v3Right.Y, this->Z / v3Right.Z);
		}

		void vec3f::operator+=(float right)
		{
			*this = vec3f(this->X + right, this->Y + right, this->Z + right);
		}

		void vec3f::operator-=(float right)
		{
			*this = vec3f(this->X - right, this->Y - right, this->Z - right);
		}

		void vec3f::operator*=(float right)
		{
			*this = vec3f(this->X * right, this->Y * right, this->Z * right);
		}

		void vec3f::operator/=(float right)
		{
			*this = vec3f(this->X / right, this->Y / right, this->Z / right);
		}

		//////////////////////////////////

		void vec3f::operator=(vec3f &v3Right)
		{
			this->X = v3Right.X;
			this->Y = v3Right.Y;
			this->Z = v3Right.Z;
		}

		bool vec3f::operator==(vec3f &v3Right)
		{
			bool x = this->X == v3Right.X;
			bool y = this->Y == v3Right.Y;
			bool z = this->Z == v3Right.Z;

			return x && y && z;
		}

		bool vec3f::operator!=(vec3f &v3Right)
		{
			bool x = this->X != v3Right.X;
			bool y = this->Y != v3Right.Y;
			bool z = this->Z != v3Right.Z;

			return x || y || z;
		}

		float& vec3f::operator[](unsigned int index)
		{
			if (index >= 3)
			{
				index = 2;
			}

			return this->Elements[index];
		}

		///////////////////////////////////

		vec3f operator+(vec3f &v3Left, vec3f &v3Right)
		{
			vec3f res = Vec3::Sum(v3Left, v3Right);
			return res;
		}

		vec3f operator-(vec3f &v3Left, vec3f &v3Right)
		{
			vec3f res = Vec3::Sub(v3Left, v3Right);
			return res;
		}

		vec3f operator*(vec3f &v3Left, vec3f &v3Right)
		{
			vec3f res = Vec3::Mul(v3Left, v3Right);
			return res;
		}

		vec3f operator/(vec3f &v3Left, vec3f &v3Right)
		{
			vec3f res = Vec3::Div(v3Left, v3Right);
			return res;
		}

		vec3f operator+(vec3f &v3Left, float right)
		{
			vec3f res = Vec3::Sum(v3Left, right);
			return res;
		}

		vec3f operator-(vec3f &v3Left, float right)
		{
			vec3f res = Vec3::Sub(v3Left, right);
			return res;
		}

		vec3f operator*(vec3f &v3Left, float right)
		{
			vec3f res = Vec3::Mul(v3Left, right);
			return res;
		}

		vec3f operator/(vec3f &v3Left, float right)
		{
			vec3f res = Vec3::Div(v3Left, right);
			return res;
		}

		vec3f operator+(float left, vec3f &v3Right)
		{
			vec3f res = Vec3::Sum(left, v3Right);
			return res;
		}

		vec3f operator-(float left, vec3f &v3Right)
		{
			vec3f res = Vec3::Sub(left, v3Right);
			return res;
		}

		vec3f operator*(float left, vec3f &v3Right)
		{
			vec3f res = Vec3::Mul(left, v3Right);
			return res;
		}

		vec3f operator/(float left, vec3f &v3Right)
		{
			vec3f res = Vec3::Div(left, v3Right);
			return res;
		}

		///////////////////////////////////

		namespace Vec3
		{
			float Length(vec3f &v3)
			{
				float result = sqrtf((v3.X * v3.X) + (v3.Y * v3.Y) + (v3.Z * v3.Z));
				return result;
			}

			float LengthSquare(vec3f &v3)
			{
				float result = ((v3.X * v3.X) + (v3.Y * v3.Y) + (v3.Z * v3.Z));
				return result;
			}

			vec3f Normalize(vec3f &v3)
			{
				float invlength = 1.0f / Length(v3);
				vec3f res = vec3f((v3.X * invlength), (v3.Y * invlength), (v3.Z * invlength));
				return res;
			}

			vec3f Sum(vec3f &v3Left, vec3f &v3Right)
			{
				vec3f res = vec3f(v3Left.X + v3Right.X, v3Left.Y + v3Right.Y, v3Left.Z + v3Right.Z);
				return res;
			}

			vec3f Sub(vec3f &v3Left, vec3f &v3Right)
			{
				vec3f res = vec3f(v3Left.X - v3Right.X, v3Left.Y - v3Right.Y, v3Left.Z - v3Right.Z);
				return res;
			}

			vec3f Mul(vec3f &v3Left, vec3f &v3Right)
			{
				vec3f res = vec3f(v3Left.X * v3Right.X, v3Left.Y * v3Right.Y, v3Left.Z * v3Right.Z);
				return res;
			}

			vec3f Div(vec3f &v3Left, vec3f &v3Right)
			{
				vec3f res = vec3f(v3Left.X / v3Right.X, v3Left.Y / v3Right.Y, v3Left.Z / v3Right.Z);
				return res;
			}

			vec3f Sum(vec3f &v3Left, float right)
			{
				vec3f res = vec3f(v3Left.X + right, v3Left.Y + right, v3Left.Z + right);
				return res;
			}

			vec3f Sub(vec3f &v3Left, float right)
			{
				vec3f res = vec3f(v3Left.X - right, v3Left.Y - right, v3Left.Z - right);
				return res;
			}

			vec3f Mul(vec3f &v3Left, float right)
			{
				vec3f res = vec3f(v3Left.X * right, v3Left.Y * right, v3Left.Z * right);
				return res;
			}

			vec3f Div(vec3f &v3Left, float right)
			{
				vec3f res = vec3f(v3Left.X / right, v3Left.Y / right, v3Left.Z / right);
				return res;
			}

			vec3f Sum(float left, vec3f &v3Right)
			{
				vec3f res = vec3f(left + v3Right.X, left + v3Right.Y, left + v3Right.Z);
				return res;
			}

			vec3f Sub(float left, vec3f &v3Right)
			{
				vec3f res = vec3f(left - v3Right.X, left - v3Right.Y, left - v3Right.Z);
				return res;
			}

			vec3f Mul(float left, vec3f &v3Right)
			{
				vec3f res = vec3f(left * v3Right.X, left * v3Right.Y, left * v3Right.Z);
				return res;
			}

			vec3f Div(float left, vec3f &v3Right)
			{
				vec3f res = vec3f(left / v3Right.X, left / v3Right.Y, left / v3Right.Z);
				return res;
			}		

			/////////////////////////////

			float Dot(vec3f &v3Left, vec3f &v3Right)
			{
				float x = v3Left.X * v3Right.X;
				float y = v3Left.Y * v3Right.Y;
				float z = v3Left.Z * v3Right.Z;

				return (x + y + z);
			}

			vec3f Cross(vec3f &v3Left, vec3f &v3Right)
			{
				float x = (v3Left.Y * v3Right.Z) - (v3Left.Z * v3Right.Y);
				float y = (v3Left.Z * v3Right.X) - (v3Left.X * v3Right.Z);
				float z = (v3Left.X * v3Right.Y) - (v3Left.Y * v3Right.X);

				return vec3f(x, y, z);
			}

			vec3f Translate(vec3f &point, vec3f &direction)
			{
				vec3f result = Mat4::Translation(direction) * point;

				return result;
			}

			vec3f Rotate(vec3f &point, vec3f &angle)
			{
				vec3f result = Mat4::Rotation(angle) * point;

				return result;
			}

			vec3f Scale(vec3f &point, vec3f &value)
			{
				vec3f result = Mat4::Scale(value) * point;

				return result;
			}
		}
	}
}
