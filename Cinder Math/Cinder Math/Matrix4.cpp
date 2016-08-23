#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		mat4f::mat4f(float value, bool diagonalOnly)
		{
			if (diagonalOnly)
			{
				Elements_2D[0][0] = value;		Elements_2D[0][1] = 0;			Elements_2D[0][2] = 0;			Elements_2D[0][3] = 0;
				Elements_2D[1][0] = 0;			Elements_2D[1][1] = value;		Elements_2D[1][2] = 0;			Elements_2D[1][3] = 0;
				Elements_2D[2][0] = 0;			Elements_2D[2][1] = 0;			Elements_2D[2][2] = value;		Elements_2D[2][3] = 0;
				Elements_2D[3][0] = 0;			Elements_2D[3][1] = 0;			Elements_2D[3][2] = 0;			Elements_2D[3][3] = value;
			}
			else
			{
				Elements_2D[0][0] = value;		Elements_2D[0][1] = value;		Elements_2D[0][2] = value;		Elements_2D[0][3] = value;
				Elements_2D[1][0] = value;		Elements_2D[1][1] = value;		Elements_2D[1][2] = value;		Elements_2D[1][3] = value;
				Elements_2D[2][0] = value;		Elements_2D[2][1] = value;		Elements_2D[2][2] = value;		Elements_2D[2][3] = value;
				Elements_2D[3][0] = value;		Elements_2D[3][1] = value;		Elements_2D[3][2] = value;		Elements_2D[3][3] = value;
			}

		}

		vec4f mat4f::operator[](unsigned int row)
		{
			if (row >= 4)
			{
				row = 3;
			}

			return vec4f(Elements_2D[row][0], Elements_2D[row][1], Elements_2D[row][2], Elements_2D[row][3]);
		}
		
		void mat4f::operator=(mat4f &other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] = other.Elements_1D[i];
			}
		}
		
		void mat4f::operator+=(mat4f &other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}
		
		void mat4f::operator-=(mat4f &other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}
		
		void mat4f::operator*=(float other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] *= other;
			}
		}
		
		void mat4f::operator*=(mat4f &other)
		{
			mat4f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					result.Elements_2D[i][j] =
						(this->Elements_2D[i][0] * other.Elements_2D[0][j]) +
						(this->Elements_2D[i][1] * other.Elements_2D[1][j]) +
						(this->Elements_2D[i][2] * other.Elements_2D[2][j]) +
						(this->Elements_2D[i][3] * other.Elements_2D[3][j]);
				}
			}

			*this = result;
		}
		
		void mat4f::operator/=(float other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] /= other;
			}
		}

		///////////////////////////////////
				
		mat4f operator+(mat4f &left, mat4f &right)
		{
			mat4f result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] + right.Elements_1D[i];
			}

			return result;
		}
		
		mat4f operator-(mat4f &left, mat4f &right)
		{
			mat4f result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] - right.Elements_1D[i];
			}

			return result;
		}
		
		mat4f operator*(mat4f &left, float right)
		{
			mat4f result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] * right;
			}

			return result;
		}
		
		mat4f operator*(mat4f &left, mat4f &right)
		{
			mat4f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					result.Elements_2D[i][j] =
						(left.Elements_2D[i][0] * right.Elements_2D[0][j]) +
						(left.Elements_2D[i][1] * right.Elements_2D[1][j]) +
						(left.Elements_2D[i][2] * right.Elements_2D[2][j]) +
						(left.Elements_2D[i][3] * right.Elements_2D[3][j]);
				}
			}

			return result;
		}
		
		vec2f operator*(mat4f &left, vec2f &right)
		{
			vec4f newRight = vec4f(right);
			vec4f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result[i] =
					(left.Elements_2D[0][i] * newRight[0]) +
					(left.Elements_2D[1][i] * newRight[1]) +
					(left.Elements_2D[2][i] * newRight[2]) +
					(left.Elements_2D[3][i] * newRight[3]);
			}

			return result.XY();
		}
		
		vec3f operator*(mat4f &left, vec3f &right)
		{
			vec4f newRight = vec4f(right);
			vec4f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result[i] =
					(left.Elements_2D[0][i] * newRight[0]) +
					(left.Elements_2D[1][i] * newRight[1]) +
					(left.Elements_2D[2][i] * newRight[2]) +
					(left.Elements_2D[3][i] * newRight[3]);
			}

			return result.XYZ();
		}
		
		vec4f operator*(mat4f &left, vec4f &right)
		{
			vec4f newRight = right;
			vec4f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result[i] =
					(left.Elements_2D[0][i] * newRight[0]) +
					(left.Elements_2D[1][i] * newRight[1]) +
					(left.Elements_2D[2][i] * newRight[2]) +
					(left.Elements_2D[3][i] * newRight[3]);
			}

			return result;
		}
				
		mat4f operator/(mat4f &left, float right)
		{
			mat4f result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] / right;
			}

			return result;
		}

		namespace Mat4
		{
			
			mat4f Sum(mat4f &left, mat4f &right)
			{
				return (left + right);
			}
			
			mat4f Sub(mat4f &left, mat4f &right)
			{
				return (left - right);
			}
			
			mat4f Mul(mat4f &left, float right)
			{
				return (left * right);
			}

			
			mat4f Mul(mat4f &left, mat4f &right)
			{
				return (left * right);
			}
			
			vec2f Mul(mat4f &left, vec2f &right)
			{
				return (left * right);
			}
			
			vec3f Mul(mat4f &left, vec3f &right)
			{
				return (left * right);
			}
						
			vec4f Mul(mat4f &left, vec4f &right)
			{
				return (left * right);
			}
			
			mat4f Div(mat4f &left, float right)
			{
				return (left / right);
			}

			mat4f Translation(vec3f &direction)
			{
				mat4f result;

				result.Elements_2D[3][0] = direction.X;
				result.Elements_2D[3][1] = direction.Y;
				result.Elements_2D[3][2] = direction.Z;

				return result;
			}

			mat4f Scale(vec3f &value)
			{
				mat4f result;

				result.Elements_2D[0][0] = value.X;
				result.Elements_2D[1][1] = value.Y;
				result.Elements_2D[2][2] = value.Z;

				return result;
			}

			mat4f Rotation(vec3f &angle)
			{
				float x = ToRadians(angle.X);
				float y = ToRadians(angle.Y);
				float z = ToRadians(angle.Z);

				mat4f rotX;
				mat4f rotY;
				mat4f rotZ;

				mat4f result;

				rotX.Elements_2D[1][1] = cosf(x);	rotX.Elements_2D[2][1] = -sinf(x);
				rotX.Elements_2D[1][2] = sinf(x);	rotX.Elements_2D[2][2] = cosf(x);

				rotY.Elements_2D[0][0] = cosf(y);	rotY.Elements_2D[2][0] = -sinf(y);
				rotY.Elements_2D[0][2] = sinf(y);	rotY.Elements_2D[2][2] = cosf(y);

				rotZ.Elements_2D[0][0] = cosf(z);	rotZ.Elements_2D[1][0] = -sinf(z);
				rotZ.Elements_2D[0][1] = sinf(z);	rotZ.Elements_2D[1][1] = cosf(z);

				result = rotX * rotY * rotZ;

				return result;
			}

			mat4f LookAt(vec3f eye, vec3f target, vec3f up)
			{
				vec3f z = Vec3::Normalize(target - eye);
				vec3f x = Vec3::Normalize(Vec3::Cross(up, z));
				vec3f y = Vec3::Cross(x, z);

				mat4f rot;

				rot.Elements_2D[0][0] = x.X;	rot.Elements_2D[1][0] = x.Y;	rot.Elements_2D[2][0] = x.Z;
				rot.Elements_2D[0][1] = y.X;	rot.Elements_2D[1][1] = y.Y;	rot.Elements_2D[2][1] = y.Z;
				rot.Elements_2D[0][2] = -z.X;	rot.Elements_2D[1][2] = -z.Y;	rot.Elements_2D[2][2] = -z.Z;

				rot.Elements_2D[3][0] = -Vec3::Dot(x, eye);
				rot.Elements_2D[3][1] = -Vec3::Dot(y, eye);
				rot.Elements_2D[3][2] = Vec3::Dot(z, eye);
				
				return rot;
			}

			mat4f Orthographic(float right, float left, float top, float bottom, float near, float far)
			{
				mat4f result;

				result.Elements_2D[0][0] = (2.0f / (right - left));	
				result.Elements_2D[0][3] = -((right + left) / (right - left));
				result.Elements_2D[1][1] = (2.0f / (top - bottom));
				result.Elements_2D[1][3] = -((top + bottom) / (top - bottom));
				result.Elements_2D[2][2] = (-2.0f / (far - near));
				result.Elements_2D[2][3] = -((far + near) / (far - near));

				return result;
			}

			mat4f Orthographic(float width, float height, float near, float far)
			{
				float top = height / 2.0f;
				float bottom = -top;

				float right = width / 2.0f;
				float left = -right;

				return Orthographic(right, left, top, bottom, near, far);
			}

			mat4f Perspective(float fieldOfView, float width, float height, float near, float far)
			{				
				float ar = width / height;
				float tanHalfFOV = tanf(ToRadians(fieldOfView / 2.0f));				

				mat4f result(0, 0);				

				result.Elements_2D[0][0] = ((1.0f) / (tanHalfFOV * ar));
				result.Elements_2D[1][1] = ((1.0f) / (tanHalfFOV));
				result.Elements_2D[2][2] = -((far + near) / (far - near));
				result.Elements_2D[2][3] = -1.0f;
				result.Elements_2D[3][2] = -((2.0f * near * far) / (far - near));

				return result;
			}
		}
	}
}
