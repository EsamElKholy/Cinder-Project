#ifndef MATRIX4_CPP
#define MATRIX4_CPP

#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		template<class T>
		Matrix4<T>::Matrix4(T value, bool diagonalOnly)
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

		template<class T>
		Vector4<T> Matrix4<T>::operator[](unsigned int row)
		{
			if (row >= 4)
			{
				row = 3;
			}

			return Vector4<T>(Elements_2D[row][0], Elements_2D[row][1], Elements_2D[row][2], Elements_2D[row][3]);
		}

		template<class T>
		void Matrix4<T>::operator=(Matrix4<T> &other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] = other.Elements_1D[i];
			}
		}

		template<class T>
		void Matrix4<T>::operator+=(Matrix4<T> &other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}

		template<class T>
		void Matrix4<T>::operator-=(Matrix4<T> &other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}

		template<class T>
		void Matrix4<T>::operator*=(T other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] *= other;
			}
		}

		template<class T>
		void Matrix4<T>::operator*=(Matrix4<T> &other)
		{
			Matrix4<T> result;

			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					result->Elements_2D[i][j] =
						(this->Elements_2D[i][0] * other.Elements_2D[0][j]) +
						(this->Elements_2D[i][1] * other.Elements_2D[1][j]) +
						(this->Elements_2D[i][2] * other.Elements_2D[2][j]) +
						(this->Elements_2D[i][3] * other.Elements_2D[3][j]);
				}
			}

			*this = result;
		}

		template<class T>
		void Matrix4<T>::operator/=(T other)
		{
			for (unsigned int i = 0; i < 16; i++)
			{
				this->Elements_1D[i] /= other;
			}
		}

		///////////////////////////////////

		template<typename T>
		Matrix4<T> operator+(Matrix4<T> &left, Matrix4<T> &right)
		{
			Matrix4<T> result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] + right.Elements_1D[i];
			}

			return result;
		}

		template<typename T>
		Matrix4<T> operator-(Matrix4<T> &left, Matrix4<T> &right)
		{
			Matrix4<T> result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] - right.Elements_1D[i];
			}

			return result;
		}

		template<typename T>
		Matrix4<T> operator*(Matrix4<T> &left, T right)
		{
			Matrix4<T> result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] * right;
			}

			return result;
		}

		template<typename T>
		Matrix4<T> operator*(Matrix4<T> &left, Matrix4<T> &right)
		{
			Matrix4<T> result;

			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					result->Elements_2D[i][j] =
						(left.Elements_2D[i][0] * right.Elements_2D[0][j]) +
						(left.Elements_2D[i][1] * right.Elements_2D[1][j]) +
						(left.Elements_2D[i][2] * right.Elements_2D[2][j]) +
						(left.Elements_2D[i][3] * right.Elements_2D[3][j]);
				}
			}

			return result;
		}

		template<typename T>
		Vector2<T> operator*(Matrix4<T> &left, Vector2<T> &right)
		{
			Vector4<T> newRight = Vector4<T>(right);
			Vector4<T> result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result[i] =
					(left.Elements_2D[i][0] * newRight[0]) +
					(left.Elements_2D[i][1] * newRight[1]) +
					(left.Elements_2D[i][2] * newRight[2]) +
					(left.Elements_2D[i][3] * newRight[3]);
			}

			return result.XY();
		}

		template<typename T>
		Vector3<T> operator*(Matrix4<T> &left, Vector3<T> &right)
		{
			Vector4<T> newRight = Vector4<T>(right);
			Vector4<T> result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result[i] =
					(left.Elements_2D[i][0] * newRight[0]) +
					(left.Elements_2D[i][1] * newRight[1]) +
					(left.Elements_2D[i][2] * newRight[2]) +
					(left.Elements_2D[i][3] * newRight[3]);
			}

			return result.XYZ();
		}

		template<typename T>
		Vector4<T> operator*(Matrix4<T> &left, Vector4<T> &right)
		{
			Vector4<T> newRight = right;
			Vector4<T> result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result[i] =
					(left.Elements_2D[i][0] * newRight[0]) +
					(left.Elements_2D[i][1] * newRight[1]) +
					(left.Elements_2D[i][2] * newRight[2]) +
					(left.Elements_2D[i][3] * newRight[3]);
			}

			return result;
		}

		template<typename T>
		Matrix4<T> operator/(Matrix4<T> &left, T right)
		{
			Matrix4<T> result;

			for (unsigned int i = 0; i < 16; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] / right;
			}

			return result;
		}

		namespace Mat4
		{
			template<typename T>
			Matrix4<T> Sum(Matrix4<T> &left, Matrix4<T> &right)
			{
				return (left + right);
			}

			template<typename T>
			Matrix4<T> Sub(Matrix4<T> &left, Matrix4<T> &right)
			{
				return (left - right);
			}

			template<typename T>
			Matrix4<T> Mul(Matrix4<T> &left, T right)
			{
				return (left * right);
			}

			template<typename T>
			Matrix4<T> Mul(Matrix4<T> &left, Matrix4<T> &right)
			{
				return (left * right);
			}

			template<typename T>
			Vector2<T> Mul(Matrix4<T> &left, Vector2<T> &right)
			{
				return (left * right);
			}

			template<typename T>
			Vector3<T> Mul(Matrix4<T> &left, Vector3<T> &right)
			{
				return (left * right);
			}

			template<typename T>
			Vector4<T> Mul(Matrix4<T> &left, Vector4<T> &right)
			{
				return (left * right);
			}

			template<typename T>
			Matrix4<T> Div(Matrix4<T> &left, T right)
			{
				return (left / right);
			}

			template<typename T>
			Matrix4<T> Translation(Vector3<T> &direction)
			{
				Matrix4<T> result;

				result.Elements_2D[0][3] = direction.X;
				result.Elements_2D[1][3] = direction.Y;
				result.Elements_2D[2][3] = direction.Z;

				return result;
			}

			template<typename T>
			Matrix4<T> Scale(Vector3<T> &value)
			{
				Matrix4<T> result;

				result.Elements_2D[0][0] = direction.X;
				result.Elements_2D[1][1] = direction.Y;
				result.Elements_2D[2][2] = direction.Z;

				return result;
			}

			template<typename T>
			Matrix4<T> Rotation(Vector3<T> &angle)
			{
				T x = ToRadians(angle.X);
				T y = ToRadians(angle.Y);
				T z = ToRadians(angle.Z);

				Matrix4<T> rotX;
				Matrix4<T> rotY;
				Matrix4<T> rotZ;

				Matrix4<T> result;

				rotX.Elements_2D[1][1] = cosf(x);	rotX.Elements_2D[1][2] = sinf(x);
				rotX.Elements_2D[2][1] = -sinf(x);	rotX.Elements_2D[2][2] = cosf(x);

				rotY.Elements_2D[0][0] = cosf(y);	rotY.Elements_2D[0][2] = sinf(y);
				rotY.Elements_2D[2][0] = -sinf(y);	rotY.Elements_2D[2][2] = cosf(y);

				rotZ.Elements_2D[0][0] = cosf(z);	rotZ.Elements_2D[0][1] = sinf(z);
				rotZ.Elements_2D[1][0] = -sinf(z);	rotZ.Elements_2D[1][1] = cosf(z);

				result = rotZ * rotY * rotX;

				return result;
			}

			template<typename T>
			Matrix4<T> LookAt(Vector3<T> &target, Vector3<T> &up)
			{
				Vector3<T> u, v, n;

				n = target;
				Vec3::Normalize(n);

				u = up;
				Vec3::Normalize(u);
				u = Vec3::Cross(u, n);

				v = Vec3::Cross(u, n);

				Matrix4<T> result;

				result.Elements_2D[0][0] = u.x;		result.Elements_2D[0][1] = u.y;		result.Elements_2D[0][2] = u.z;
				result.Elements_2D[1][0] = v.x;		result.Elements_2D[1][1] = v.y;		result.Elements_2D[1][2] = v.z;
				result.Elements_2D[2][0] = n.x;		result.Elements_2D[2][1] = n.y;		result.Elements_2D[2][2] = n.z;

				return result;
			}

			template<typename T>
			Matrix4<T> Orthographic(float right, float left, float top, float bottom, float near, float far)
			{
				Matrix4<T> result;

				result.Elements_2D[0][0] = (2.0f / (right - left));																													result.Elements_2D[0][3] = -((right + left) / (right - left));
				result.Elements_2D[1][1] = (2.0f / (top - bottom));
				result.Elements_2D[1][3] = -((top + bottom) / (top - bottom));
				result.Elements_2D[2][2] = (-2.0f / (far - near));
				result.Elements_2D[2][3] = -((far + near) / (far - near));

				return result;
			}

			template<typename T>
			Matrix4<T> Orthographic(float width, float height, float near, float far)
			{
				float top = height / 2.0f;
				float bottom = -top;

				float right = width / 2.0f;
				float left = -right;

				return Orthographic(right, left, top, bottom, near, far);
			}

			template<typename T>
			Matrix4<T> Perspective(float fieldOfView, float width, float height, float near, float far)
			{
				float ar = width / height;
				float tanHalfFOV = tanf(ToRadians((fieldOfView) / 2.0f));
				float top = near * tanHalfFOV;
				float bottom = -top;
				float right = ar * top;
				float left = -right;

				Matrix4<T> result;

				result.Elements_2D[0][0] = ((2.0f * near) / (right - left));
				result.Elements_2D[0][2] = ((right + left) / (right - left));
				result.Elements_2D[1][1] = ((2.0f * near) / (top - bottom));
				result.Elements_2D[1][2] = ((top + bottom) / (top - bottom));
				result.Elements_2D[2][2] = -((far + near) / (far - near));
				result.Elements_2D[2][3] = -((2.0f * far * near) / (far - near));
				result.Elements_2D[3][2] = -1;

				return result;
			}
		}
	}
}

#endif