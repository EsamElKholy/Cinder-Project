#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		mat3f::mat3f(float value, bool diagonalOnly)
		{
			if (diagonalOnly)
			{
				Elements_2D[0][0] = value;		Elements_2D[0][1] = 0;		Elements_2D[0][2] = 0;
				Elements_2D[1][0] = 0;			Elements_2D[1][1] = value;	Elements_2D[1][2] = 0;
				Elements_2D[2][0] = 0;			Elements_2D[2][1] = 0;		Elements_2D[2][2] = value;
			}
			else
			{
				Elements_2D[0][0] = value;		Elements_2D[0][1] = value;	Elements_2D[0][2] = value;
				Elements_2D[1][0] = value;		Elements_2D[1][1] = value;	Elements_2D[1][2] = value;
				Elements_2D[2][0] = value;		Elements_2D[2][1] = value;	Elements_2D[2][2] = value;
			}

		}

		vec3f mat3f::operator[](unsigned int row)
		{
			if (row >= 3)
			{
				row = 2;
			}

			return vec3f(Elements_2D[row][0], Elements_2D[row][1], Elements_2D[row][2]);
		}

		void mat3f::operator=(mat3f &other)
		{
			for (unsigned int i = 0; i < 9; i++)
			{
				this->Elements_1D[i] = other.Elements_1D[i];
			}
		}

		void mat3f::operator+=(mat3f &other)
		{
			for (unsigned int i = 0; i < 9; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}

		void mat3f::operator-=(mat3f &other)
		{
			for (unsigned int i = 0; i < 9; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}

		void mat3f::operator*=(float other)
		{
			for (unsigned int i = 0; i < 9; i++)
			{
				this->Elements_1D[i] *= other;
			}
		}

		void mat3f::operator*=(mat3f &other)
		{
			mat3f result;

			for (unsigned int i = 0; i < 3; i++)
			{
				for (unsigned int j = 0; j < 3; j++)
				{
					result.Elements_2D[i][j] =
						(this->Elements_2D[i][0] * other.Elements_2D[0][j]) +
						(this->Elements_2D[i][1] * other.Elements_2D[1][j]) +
						(this->Elements_2D[i][2] * other.Elements_2D[2][j]);
				}
			}

			*this = result;
		}

		void mat3f::operator/=(float other)
		{
			for (unsigned int i = 0; i < 9; i++)
			{
				this->Elements_1D[i] /= other;
			}
		}

		///////////////////////////////////

		float mat3f::GetMinor(int r0, int r1, int c0, int c1)
		{
			mat2f res;

			res.Elements_2D[0][0] = this->Elements_2D[r0][c0];
			res.Elements_2D[0][1] = this->Elements_2D[r0][c1];
			res.Elements_2D[1][0] = this->Elements_2D[r1][c0];
			res.Elements_2D[1][1] = this->Elements_2D[r1][c1];

			return res.Determinant();
		}

		mat3f mat3f::Inverse()
		{
			float n00 = GetMinor(1, 2, 1, 2);
			float n01 = GetMinor(1, 2, 0, 2);
			float n02 = GetMinor(1, 2, 0, 1);

			float n10 = GetMinor(0, 2, 1, 2);
			float n11 = GetMinor(0, 2, 0, 2);
			float n12 = GetMinor(0, 2, 0, 1);

			float n20 = GetMinor(0, 1, 1, 2);
			float n21 = GetMinor(0, 1, 0, 2);
			float n22 = GetMinor(0, 1, 0, 1);

			mat3f res;

			res.Elements_2D[0][0] = n00;
			res.Elements_2D[0][1] = n01;
			res.Elements_2D[0][2] = n02;
			
			res.Elements_2D[1][0] = n10;
			res.Elements_2D[1][1] = n11;
			res.Elements_2D[1][2] = n12;
			
			res.Elements_2D[2][0] = n20;
			res.Elements_2D[2][1] = n21;
			res.Elements_2D[2][2] = n22;

			float det = (this->Elements_2D[0][0] * n00) - (this->Elements_2D[1][1] * n11) + (this->Elements_2D[2][2] * n22);

			det = 1.0f / det;


			float checker[3][3];

			checker[0][0] = 1;
			checker[0][1] = -1;
			checker[0][2] = 1;

			checker[1][0] = -1;
			checker[1][1] = 1;
			checker[1][2] = -1;


			checker[2][0] = 1;
			checker[2][1] = -1;
			checker[2][2] = 1;


			for (unsigned int i = 0; i < 3; i++)
			{
				for (unsigned int j = 0; j < 3; j++)
				{
					res.Elements_2D[i][j] *= det * checker[i][j];
				}
			}

			return res.Transpose();
		}

		mat3f mat3f::Transpose()
		{
			mat3f res;

			res.Elements_2D[0][0] = this->Elements_2D[0][0];
			res.Elements_2D[0][1] = this->Elements_2D[1][0];
			res.Elements_2D[0][2] = this->Elements_2D[2][0];
			
			res.Elements_2D[1][0] = this->Elements_2D[0][1];
			res.Elements_2D[1][1] = this->Elements_2D[1][1];
			res.Elements_2D[1][2] = this->Elements_2D[2][1];
			
			res.Elements_2D[2][0] = this->Elements_2D[0][2];
			res.Elements_2D[2][1] = this->Elements_2D[1][2];
			res.Elements_2D[2][2] = this->Elements_2D[2][2];

			return res;
		}

		float mat3f::Determinant()
		{
			float n00 = this->Elements_2D[0][0] * GetMinor(1, 2, 1, 2);
			float n11 = this->Elements_2D[1][1] * GetMinor(0, 2, 0, 2);
			float n22 = this->Elements_2D[2][2] * GetMinor(0, 1, 0, 1);

			return n00 - n11 + n22;
		}

		/////////////////////////////////////////////

		mat3f operator+(mat3f &left, mat3f &right)
		{
			mat3f result;

			for (unsigned int i = 0; i < 9; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] + right.Elements_1D[i];
			}

			return result;
		}

		mat3f operator-(mat3f &left, mat3f &right)
		{
			mat3f result;

			for (unsigned int i = 0; i < 9; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] - right.Elements_1D[i];
			}

			return result;
		}

		mat3f operator*(mat3f &left, float right)
		{
			mat3f result;

			for (unsigned int i = 0; i < 9; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] * right;
			}

			return result;
		}

		mat3f operator*(mat3f &left, mat3f &right)
		{
			mat3f result;

			for (unsigned int i = 0; i < 3; i++)
			{
				for (unsigned int j = 0; j < 3; j++)
				{
					result.Elements_2D[i][j] =
						(left.Elements_2D[i][0] * right.Elements_2D[0][j]) +
						(left.Elements_2D[i][1] * right.Elements_2D[1][j]) + 
						(left.Elements_2D[i][2] * right.Elements_2D[2][j]);
				}
			}

			return result;
		}

		mat3f operator/(mat3f &left, float right)
		{
			mat3f result;

			for (unsigned int i = 0; i < 9; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] / right;
			}

			return result;
		}
	}
}