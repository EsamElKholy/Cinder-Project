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

		float mat4f::GetMinor(int r0, int r1, int r2, int c0, int c1, int c2)
		{
			mat3f res;

			res.Elements_2D[0][0] = this->Elements_2D[r0][c0];
			res.Elements_2D[0][1] = this->Elements_2D[r0][c1];
			res.Elements_2D[0][2] = this->Elements_2D[r0][c2];

			res.Elements_2D[1][0] = this->Elements_2D[r1][c0];
			res.Elements_2D[1][1] = this->Elements_2D[r1][c1];
			res.Elements_2D[1][2] = this->Elements_2D[r1][c2];


			res.Elements_2D[2][0] = this->Elements_2D[r2][c0];
			res.Elements_2D[2][1] = this->Elements_2D[r2][c1];
			res.Elements_2D[2][2] = this->Elements_2D[r2][c2];

			return res.Determinant();
		}

		float mat4f::Determinant() 
		{
			float n00 = this->Elements_2D[0][0] * GetMinor(1, 2, 3, 1, 2, 3);
			float n01 = this->Elements_2D[0][1] * GetMinor(1, 2, 3, 0, 2, 3);
			float n02 = this->Elements_2D[0][2] * GetMinor(1, 2, 3, 0, 1, 3);
			float n03 = this->Elements_2D[0][3] * GetMinor(1, 2, 3, 0, 1, 2);

			return n00 - n01 + n02 - n03;
		}

		mat4f mat4f::Transpose() 
		{
			mat4f res;

			res.Elements_2D[0][0] = this->Elements_2D[0][0];
			res.Elements_2D[0][1] = this->Elements_2D[1][0];
			res.Elements_2D[0][2] = this->Elements_2D[2][0];
			res.Elements_2D[0][3] = this->Elements_2D[3][0];

			res.Elements_2D[1][0] = this->Elements_2D[0][1];
			res.Elements_2D[1][1] = this->Elements_2D[1][1];
			res.Elements_2D[1][2] = this->Elements_2D[2][1];
			res.Elements_2D[1][3] = this->Elements_2D[3][1];

			res.Elements_2D[2][0] = this->Elements_2D[0][2];
			res.Elements_2D[2][1] = this->Elements_2D[1][2];
			res.Elements_2D[2][2] = this->Elements_2D[2][2];
			res.Elements_2D[2][3] = this->Elements_2D[3][2];

			res.Elements_2D[3][0] = this->Elements_2D[0][3];
			res.Elements_2D[3][1] = this->Elements_2D[1][3];
			res.Elements_2D[3][2] = this->Elements_2D[2][3];
			res.Elements_2D[3][3] = this->Elements_2D[3][3];

			return res;
		}

		mat4f mat4f::Inverse() 
		{
			float n00 = GetMinor(1, 2, 3, 1, 2, 3);
			float n01 = GetMinor(1, 2, 3, 0, 2, 3);
			float n02 = GetMinor(1, 2, 3, 0, 1, 3);
			float n03 = GetMinor(1, 2, 3, 0, 1, 2);
								
			float n10 = GetMinor(0, 2, 3, 1, 2, 3);
			float n11 = GetMinor(0, 2, 3, 0, 2, 3);
			float n12 = GetMinor(0, 2, 3, 0, 1, 3);
			float n13 = GetMinor(0, 2, 3, 0, 1, 2);
							
			float n20 = GetMinor(0, 1, 3, 1, 2, 3);
			float n21 = GetMinor(0, 1, 3, 0, 2, 3);
			float n22 = GetMinor(0, 1, 3, 0, 1, 3);
			float n23 = GetMinor(0, 1, 3, 0, 1, 2);
							
			float n30 = GetMinor(0, 1, 2, 1, 2, 3);
			float n31 = GetMinor(0, 1, 2, 0, 2, 3);
			float n32 = GetMinor(0, 1, 2, 0, 1, 3);
			float n33 = GetMinor(0, 1, 2, 0, 1, 2);
			
			mat4f res;

			float minMat[4][4] = 
			{
				{n00, n01, n02, n03},
				{n10, n11, n12, n13},
				{n20, n21, n22, n23},
				{n30, n31, n32, n33}
			};

			float det =
				(  this->Elements_2D[0][0] * n00)
				- (this->Elements_2D[0][1] * n01)
				+ (this->Elements_2D[0][2] * n02)
				- (this->Elements_2D[0][3] * n03);

			det = 1.0f / det;

			float checker[4][4] = 
			{
				{1, -1, 1, -1},
				{-1, 1, -1, 1},
				{1, -1, 1, -1},
				{-1, 1, -1, 1}
			};

			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					minMat[i][j] *= det * checker[i][j];
					res.Elements_2D[i][j] = minMat[i][j];
				}
			}

			return res.Transpose();
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
			vec4f newRight = vec4f(right, 0, 1);
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
			vec4f newRight = vec4f(right, 1);
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

			mat4f Rotation(float &angle, vec3f &axis) 
			{
				mat4f res;

				float r = ToRadians(angle);

				float c = cosf(r);
				float s = sinf(r);

				float omc = 1.0f - c;

				vec3f x = vec3f(c + (axis.X * omc), (axis.X * axis.Y * omc) + (axis.Z * s), (axis.X * axis.Z * omc) - (axis.Y * s));
				vec3f y = vec3f((axis.X * axis.Y * omc) - (axis.Z * s), c + (axis.Y * omc), (axis.Y * axis.Z * omc) + (axis.X * s));
				vec3f z = vec3f((axis.X * axis.Z * omc) + (axis.Y * s), (axis.Y * axis.Z * omc) - (axis.X * s), c + (axis.Z * omc));

				res.Elements_2D[0][0] = x.X;	res.Elements_2D[0][1] = y.X;	res.Elements_2D[0][2] = z.X;
				res.Elements_2D[1][0] = x.Y;	res.Elements_2D[1][1] = y.Y;	res.Elements_2D[1][2] = z.Y;
				res.Elements_2D[2][0] = x.Z;	res.Elements_2D[2][1] = y.Z;	res.Elements_2D[2][2] = z.Z;
			
				return res;
			}

			mat4f Rotation(vec3f &dir, vec3f &up)
			{
				mat4f res;

				vec3f f = Vec3::Normalize(dir);
				vec3f r = Vec3::Normalize(up);
				r = Vec3::Cross(r, f);

				vec3f u = Vec3::Cross(f, r);

				res.Elements_2D[0][0] = r.X;	res.Elements_2D[0][1] = u.X;	res.Elements_2D[0][2] = f.X;
				res.Elements_2D[1][0] = r.Y;	res.Elements_2D[1][1] = u.Y;	res.Elements_2D[1][2] = f.Y;
				res.Elements_2D[2][0] = r.Z;	res.Elements_2D[2][1] = u.Z;	res.Elements_2D[2][2] = f.Z;

				return res;
			}

			mat4f Rotation(vec3f &forward, vec3f &right, vec3f &up) 
			{
				mat4f res;

				vec3f r = Vec3::Normalize(right);
				vec3f u = Vec3::Normalize(up);
				vec3f f = Vec3::Normalize(forward);

				res.Elements_2D[0][0] = r.X;	res.Elements_2D[0][1] = r.Y;	res.Elements_2D[0][2] = r.Z;
				res.Elements_2D[1][0] = u.X;	res.Elements_2D[1][1] = u.Y;	res.Elements_2D[1][2] = u.Z;
				res.Elements_2D[2][0] = f.X;	res.Elements_2D[2][1] = f.Y;	res.Elements_2D[2][2] = f.Z;

				return res;
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

				/*rot.Elements_2D[3][0] = -Vec3::Dot(x, eye);
				rot.Elements_2D[3][1] = -Vec3::Dot(y, eye);
				rot.Elements_2D[3][2] = Vec3::Dot(z, eye);*/
				
				return rot;
			}

			mat4f Orthographic(float right, float left, float top, float bottom, float near, float far)
			{
				mat4f result;

				result.Elements_2D[0][0] = (2.0f / (right - left));
				result.Elements_2D[3][0] = -((right + left) / (right - left));
				result.Elements_2D[1][1] = (2.0f / (top - bottom));
				result.Elements_2D[3][1] = -((top + bottom) / (top - bottom));
				result.Elements_2D[2][2] = (-2.0f / (far - near));
				result.Elements_2D[3][2] = -((far + near) / (far - near));

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
