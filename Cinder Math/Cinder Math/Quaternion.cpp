#include "CinderMath.h"
namespace Cinder
{
	namespace Math
	{
		quatf::quatf(float &angle, vec3f &axis)
		{
			vec3f a = Vec3::Normalize(axis);

			float sh = sinf(ToRadians(angle) / 2.0f);
			float ch = cosf(ToRadians(angle) / 2.0f);

			this->X = a.X * sh;
			this->Y = a.Y * sh;
			this->Z = a.Z * sh;
			this->W = ch;
		}

		quatf::quatf(mat4f &m)
		{
			quatf res;

			float x = 0;
			float y = 0;
			float z = 0;
			float w = 0;

			float trace = m.Elements_2D[0][0] + m.Elements_2D[1][1] + m.Elements_2D[2][2];

			if (trace > 0)
			{
				float s = 0.5f / sqrtf(trace + 1.0f);

				w = 0.25f / s;
				x = (m.Elements_2D[2][1] - m.Elements_2D[1][2]) * s;
				y = (m.Elements_2D[0][2] - m.Elements_2D[2][0]) * s;
				z = (m.Elements_2D[1][0] - m.Elements_2D[0][1]) * s;
			}
			else
			{
				if (m.Elements_2D[0][0] > m.Elements_2D[1][1] && m.Elements_2D[0][0] > m.Elements_2D[2][2])
				{
					float s = 2.0f * sqrtf(1.0f + m.Elements_2D[0][0] - m.Elements_2D[1][1] - m.Elements_2D[2][2]);

					w = (m.Elements_2D[2][1] - m.Elements_2D[1][2]) / s;
					x = 0.25f * s;
					y = (m.Elements_2D[0][1] + m.Elements_2D[1][0]) / s;
					z = (m.Elements_2D[0][2] + m.Elements_2D[2][0]) / s;
				}
				else if (m.Elements_2D[1][1] > m.Elements_2D[2][2])
				{
					float s = 2.0f * sqrtf(1.0f + m.Elements_2D[1][1] - m.Elements_2D[0][0] - m.Elements_2D[2][2]);

					w = (m.Elements_2D[0][2] - m.Elements_2D[2][0]) / s;
					x = (m.Elements_2D[0][1] + m.Elements_2D[1][0]) / s;
					y = 0.25f * s;
					z = (m.Elements_2D[1][2] + m.Elements_2D[2][1]) / s;
				}
				else
				{
					float s = 2.0f * sqrtf(1.0f + m.Elements_2D[2][2] - m.Elements_2D[0][0] - m.Elements_2D[1][1]);

					w = (m.Elements_2D[1][0] - m.Elements_2D[0][1]) / s;
					x = (m.Elements_2D[0][2] + m.Elements_2D[2][0]) / s;
					y = (m.Elements_2D[2][1] + m.Elements_2D[1][2]) / s;
					z = 0.25f * s;
				}
			}

			res.X = x;
			res.Y = y;
			res.Z = z;
			res.W = w;

			float invLen = 1.0f / Quat::Length(res);

			res.X *= invLen;
			res.Y *= invLen;
			res.Z *= invLen;
			res.W *= invLen;

			this->X = res.X;
			this->Y = res.Y;
			this->Z = res.Z;
			this->W = res.W;
		}

		/////////////////////////////////////


		void quatf::operator=(quatf &v4Right)
		{
			this->X = v4Right.X;
			this->Y = v4Right.Y;
			this->Z = v4Right.Z;
			this->W = v4Right.W;
		}


		bool quatf::operator==(quatf &v4Right)
		{
			bool x = this->X == v4Right.X;
			bool y = this->Y == v4Right.Y;
			bool z = this->Z == v4Right.Z;
			bool w = this->W == v4Right.W;

			return x && y && z && w;
		}


		bool quatf::operator!=(quatf &v4Right)
		{
			bool x = this->X != v4Right.X;
			bool y = this->Y != v4Right.Y;
			bool z = this->Z != v4Right.Z;
			bool w = this->W != v4Right.W;

			return x || y || z || w;
		}

		float& quatf::operator[](unsigned int index)
		{
			if (index >= 4)
			{
				index = 3;
			}

			return this->Elements[index];
		}

		////////////////////////////////////////////


		void quatf::operator+=(quatf &v4Right)
		{
			*this = quatf(this->X + v4Right.X, this->Y + v4Right.Y, this->Z + v4Right.Z, this->W + v4Right.W);
		}


		void quatf::operator-=(quatf &v4Right)
		{
			*this = quatf(this->X - v4Right.X, this->Y - v4Right.Y, this->Z - v4Right.Z, this->W - v4Right.W);
		}


		void quatf::operator*=(quatf &q)
		{
			quatf res;

			res.X = (this->X * q.W) + (this->W * q.X) + (this->Y * q.Z) - (this->Z * q.Y);
			res.Y = (this->Y * q.W) + (this->W * q.Y) + (this->Z * q.X) - (this->X * q.Z);
			res.Z = (this->Z * q.W) + (this->W * q.Z) + (this->X * q.Y) - (this->Y * q.X);
			res.W = (this->W * q.W) - (this->X * q.X) - (this->Y * q.Y) - (this->Z * q.Z);

			this->X = res.X;
			this->Y = res.Y;
			this->Z = res.Z;
			this->W = res.W;
		}

		void quatf::operator*=(vec3f &v)
		{
			quatf res;

			res.X = (this->W * v.X) + (this->Y * v.Z) - (this->Z * v.Y);
			res.Y = (this->W * v.Y) + (this->Z * v.X) - (this->X * v.Z);
			res.Z = (this->W * v.Z) + (this->X * v.Y) - (this->Y * v.X);
			res.W = -(this->X * v.X) - (this->Y * v.Y) - (this->Z * v.Z);

			this->X = res.X;
			this->Y = res.Y;
			this->Z = res.Z;
			this->W = res.W;
		}
		
		void quatf::operator/=(quatf &v4Right)
		{
			*this = quatf(this->X / v4Right.X, this->Y / v4Right.Y, this->Z / v4Right.Z, this->W / v4Right.W);
		}


		void quatf::operator+=(float right)
		{
			*this = quatf(this->X + right, this->Y + right, this->Z + right, this->W + right);
		}


		void quatf::operator-=(float right)
		{
			*this = quatf(this->X - right, this->Y - right, this->Z - right, this->W - right);
		}


		void quatf::operator*=(float right)
		{
			*this = quatf(this->X * right, this->Y * right, this->Z * right, this->W * right);
		}


		void quatf::operator/=(float right)
		{
			*this = quatf(this->X / right, this->Y / right, this->Z / right, this->W / right);
		}

		////////////////////////////////////////////

		quatf operator+(quatf &v4Left, quatf &v4Right)
		{
			quatf res = Quat::Sum(v4Left, v4Right);
			return res;
		}

		quatf operator-(quatf &v4Left, quatf &v4Right)
		{
			quatf res = Quat::Sub(v4Left, v4Right);
			return res;
		}

		quatf operator*(quatf &q1, quatf &q2)
		{
			quatf res;

			res.X = (q1.X * q2.W) + (q1.W * q2.X) + (q1.Y * q2.Z) - (q1.Z * q2.Y);
			res.Y = (q1.Y * q2.W) + (q1.W * q2.Y) + (q1.Z * q2.X) - (q1.X * q2.Z);
			res.Z = (q1.Z * q2.W) + (q1.W * q2.Z) + (q1.X * q2.Y) - (q1.Y * q2.X);
			res.W = (q1.W * q2.W) - (q1.X * q2.X) - (q1.Y * q2.Y) - (q1.Z * q2.Z);

			return res;
		}

		quatf operator*(quatf &q, vec3f &v)
		{
			quatf res;

			res.X = (q.W * v.X) + (q.Y * v.Z) - (q.Z * v.Y);
			res.Y = (q.W * v.Y) + (q.Z * v.X) - (q.X * v.Z);
			res.Z = (q.W * v.Z) + (q.X * v.Y) - (q.Y * v.X);
			res.W = -(q.X * v.X) - (q.Y * v.Y) - (q.Z * v.Z);
			
			return res;
		}

		quatf operator/(quatf &v4Left, quatf &v4Right)
		{
			quatf res = Quat::Div(v4Left, v4Right);
			return res;
		}

		quatf operator+(quatf &v4Left, float right)
		{
			quatf res = Quat::Sum(v4Left, right);
			return res;
		}

		quatf operator-(quatf &v4Left, float right)
		{
			quatf res = Quat::Sub(v4Left, right);
			return res;
		}

		quatf operator*(quatf &v4Left, float right)
		{
			quatf res = Quat::Mul(v4Left, right);
			return res;
		}

		quatf operator/(quatf &v4Left, float right)
		{
			quatf res = Quat::Div(v4Left, right);
			return res;
		}

		quatf operator+(float left, quatf &v4Right)
		{
			quatf res = Quat::Sum(left, v4Right);
			return res;
		}

		quatf operator-(float left, quatf &v4Right)
		{
			quatf res = Quat::Sub(left, v4Right);
			return res;
		}

		quatf operator*(float left, quatf &v4Right)
		{
			quatf res = Quat::Mul(left, v4Right);
			return res;
		}

		quatf operator/(float left, quatf &v4Right)
		{
			quatf res = Quat::Div(left, v4Right);
			return res;
		}

		/////////////////			

		mat4f quatf::ToRotationMatrix()
		{
			quatf q = Quat::Normalize(*this);

			float x = q.X, y = q.Y, z = q.Z, w = q.W,

				x2 = x + x,

				y2 = y + y,

				z2 = z + z,

				xx = x * x2,

				yx = y * x2,

				yy = y * y2,

				zx = z * x2,

				zy = z * y2,

				zz = z * z2,

				wx = w * x2,

				wy = w * y2,

				wz = w * z2;

			mat4f out;

			out.Elements_2D[0][0] = 1 - yy - zz;

			out.Elements_2D[0][1] = yx + wz;

			out.Elements_2D[0][2] = zx - wy;

			out.Elements_2D[0][3] = 0;

			out.Elements_2D[1][0] = yx - wz;

			out.Elements_2D[1][1] = 1 - xx - zz;

			out.Elements_2D[1][2] = zy + wx;

			out.Elements_2D[1][3] = 0;

			out.Elements_2D[2][0] = zx + wy;

			out.Elements_2D[2][1] = zy - wx;

			out.Elements_2D[2][2] = 1 - xx - yy;

			out.Elements_2D[2][3] = 0;

			out.Elements_2D[3][0] = 0;

			out.Elements_2D[3][1] = 0;

			out.Elements_2D[3][2] = 0;

			out.Elements_2D[3][3] = 1;

			return out;
		}

		vec3f quatf::GetUp()
		{
			vec3f res = Vec3::Rotate(vec3f(0, 1, 0), *this);

			return res;
		}

		vec3f quatf::GetDown()
		{
			vec3f res = Vec3::Rotate(vec3f(0, -1, 0), *this);

			return res;
		}

		vec3f quatf::GetFront()
		{
			vec3f res = Vec3::Rotate(vec3f(0, 0, 1), *this);

			return res;
		}

		vec3f quatf::GetBack()
		{
			vec3f res = Vec3::Rotate(vec3f(0, 0, -1), *this);

			return res;
		}

		vec3f quatf::GetRight()
		{
			vec3f res = Vec3::Rotate(vec3f(1, 0, 0), *this);

			return res;
		}

		vec3f quatf::GetLeft()
		{
			vec3f res = Vec3::Rotate(vec3f(-1, 0, 0), *this);

			return res;
		}

		namespace Quat
		{
			float Length(quatf &v4)
			{
				float result = sqrtf((v4.X * v4.X) + (v4.Y * v4.Y) + (v4.Z * v4.Z) + (v4.W * v4.W));
				return result;
			}

			float LengthSquare(quatf &v4)
			{
				float result = ((v4.X * v4.X) + (v4.Y * v4.Y) + (v4.Z * v4.Z) + (v4.W * v4.W));
				return result;
			}

			quatf Normalize(quatf &v4)
			{
				float length = 1.0f / Length(v4);
				quatf res = quatf((v4.X * length), (v4.Y * length), (v4.Z * length), (v4.W * length));
				return res;
			}

			quatf Sum(quatf &v4Left, quatf &v4Right)
			{
				quatf res = quatf(v4Left.X + v4Right.X, v4Left.Y + v4Right.Y, v4Left.Z + v4Right.Z, v4Left.W + v4Right.W);
				return res;
			}

			quatf Sub(quatf &v4Left, quatf &v4Right)
			{
				quatf res = quatf(v4Left.X - v4Right.X, v4Left.Y - v4Right.Y, v4Left.Z - v4Right.Z, v4Left.W - v4Right.W);
				return res;
			}

			quatf Mul(quatf &q1, quatf &q2)
			{
				return q1 * q2;
			}

			quatf Mul(quatf &q, vec3f &v)
			{
				return q * v;
			}

			quatf Div(quatf &v4Left, quatf &v4Right)
			{
				quatf res = quatf(v4Left.X / v4Right.X, v4Left.Y / v4Right.Y, v4Left.Z / v4Right.Z, v4Left.W / v4Right.W);
				return res;
			}

			quatf Sum(quatf &v4Left, float right)
			{
				quatf res = quatf(v4Left.X + right, v4Left.Y + right, v4Left.Z + right, v4Left.W + right);
				return res;
			}

			quatf Sub(quatf &v4Left, float right)
			{
				quatf res = quatf(v4Left.X - right, v4Left.Y - right, v4Left.Z - right, v4Left.W - right);
				return res;
			}

			quatf Mul(quatf &v4Left, float right)
			{
				quatf res = quatf(v4Left.X * right, v4Left.Y * right, v4Left.Z * right, v4Left.W * right);
				return v4Left;
			}

			quatf Div(quatf &v4Left, float right)
			{
				quatf res = quatf(v4Left.X / right, v4Left.Y / right, v4Left.Z / right, v4Left.W / right);
				return res;
			}

			quatf Sum(float left, quatf &v4Right)
			{
				quatf res = quatf(left + v4Right.X, left + v4Right.Y, left + v4Right.Z, left + v4Right.W);
				return res;
			}

			quatf Sub(float left, quatf &v4Right)
			{
				quatf res = quatf(left - v4Right.X, left - v4Right.Y, left - v4Right.Z, left - v4Right.W);
				return res;
			}

			quatf Mul(float left, quatf &v4Right)
			{
				quatf res = quatf(left * v4Right.X, left * v4Right.Y, left * v4Right.Z, left * v4Right.W);
				return res;
			}

			quatf Div(float left, quatf &v4Right)
			{
				quatf res = quatf(left / v4Right.X, left / v4Right.Y, left / v4Right.Z, left / v4Right.W);
				return res;
			}

			quatf Conjugate(quatf &q) 
			{
				return quatf(q.X * -1.0f, q.Y * -1.0f, q.Z * -1.0f, q.W);
			}

			quatf RotateX(float &angle, quatf &q)
			{
				quatf result;

				float sh = sinf(ToRadians(angle) / 2.0f);
				float ch = cosf(ToRadians(angle) / 2.0f);

				result.X = q.X * ch + q.W * sh;
				result.Y = q.Y * ch + q.Z * sh;
				result.Z = q.Z * ch - q.Y * sh;
				result.W = q.W * ch - q.X * sh;

				return result;
			}

			quatf RotateY(float &angle, quatf &q)
			{
				quatf result;

				float sh = sinf(ToRadians(angle) / 2.0f);
				float ch = cosf(ToRadians(angle) / 2.0f);

				result.X = q.X * ch - q.Z * sh;
				result.Y = q.Y * ch + q.W * sh;
				result.Z = q.Z * ch + q.X * sh;
				result.W = q.W * ch - q.Y * sh;

				return result;
			}

			quatf RotateZ(float &angle, quatf &q)
			{
				quatf result;

				float sh = sinf(ToRadians(angle) / 2.0f);
				float ch = cosf(ToRadians(angle) / 2.0f);

				result.X = q.X * ch + q.Y * sh;
				result.Y = q.Y * ch - q.X * sh;
				result.Z = q.Z * ch + q.W * sh;
				result.W = q.W * ch - q.Z * sh;

				return result;
			}
		}
	}
}
