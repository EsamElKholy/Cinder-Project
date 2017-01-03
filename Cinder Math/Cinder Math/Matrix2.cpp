#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		mat2f::mat2f(float value, bool diagonalOnly)
		{
			if (diagonalOnly)
			{
				Elements_2D[0][0] = value;		Elements_2D[0][1] = 0;		
				Elements_2D[1][0] = 0;			Elements_2D[1][1] = value;
			}
			else
			{
				Elements_2D[0][0] = value;		Elements_2D[0][1] = value;	
				Elements_2D[1][0] = value;		Elements_2D[1][1] = value;
			}

		}

		vec2f mat2f::operator[](unsigned int row)
		{
			if (row >= 2)
			{
				row = 1;
			}

			return vec2f(Elements_2D[row][0], Elements_2D[row][1]);
		}

		void mat2f::operator=(mat2f &other)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				this->Elements_1D[i] = other.Elements_1D[i];
			}
		}

		void mat2f::operator+=(mat2f &other)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}

		void mat2f::operator-=(mat2f &other)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				this->Elements_1D[i] += other.Elements_1D[i];
			}
		}

		void mat2f::operator*=(float other)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				this->Elements_1D[i] *= other;
			}
		}

		void mat2f::operator*=(mat2f &other)
		{
			mat2f result;

			for (unsigned int i = 0; i < 2; i++)
			{
				for (unsigned int j = 0; j < 2; j++)
				{
					result.Elements_2D[i][j] =
						(this->Elements_2D[i][0] * other.Elements_2D[0][j]) +
						(this->Elements_2D[i][1] * other.Elements_2D[1][j]);
				}
			}

			*this = result;
		}

		void mat2f::operator/=(float other)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				this->Elements_1D[i] /= other;
			}
		}

		///////////////////////////////////

		mat2f mat2f::Inverse()
		{
			float d = Determinant();
			d = 1.0f / d;
			
			mat2f res;

			res.Elements_2D[0][0] = d * this->Elements_2D[1][1];
			res.Elements_2D[0][1] = -d * this->Elements_2D[0][1];
			res.Elements_2D[1][0] = -d * this->Elements_2D[1][0];
			res.Elements_2D[1][1] = d * this->Elements_2D[0][0];

			return res;
		}

		mat2f mat2f::Transpose()
		{
			mat2f res;

			res.Elements_2D[0][0] = this->Elements_2D[0][0];
			res.Elements_2D[0][1] = this->Elements_2D[1][0];
			res.Elements_2D[1][0] = this->Elements_2D[0][1];
			res.Elements_2D[1][1] = this->Elements_2D[1][1];

			return res;
		}

		float mat2f::Determinant()
		{
			return ((this->Elements_2D[0][0] * this->Elements_2D[1][1]) - (this->Elements_2D[0][1] * this->Elements_2D[1][0]));
		}

		/////////////////////////////////////////////

		mat2f operator+(mat2f &left, mat2f &right)
		{
			mat2f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] + right.Elements_1D[i];
			}

			return result;
		}

		mat2f operator-(mat2f &left, mat2f &right)
		{
			mat2f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] - right.Elements_1D[i];
			}

			return result;
		}

		mat2f operator*(mat2f &left, float right)
		{
			mat2f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] * right;
			}

			return result;
		}

		mat2f operator*(mat2f &left, mat2f &right)
		{
			mat2f result;

			for (unsigned int i = 0; i < 2; i++)
			{
				for (unsigned int j = 0; j < 2; j++)
				{
					result.Elements_2D[i][j] =
						(left.Elements_2D[i][0] * right.Elements_2D[0][j]) +
						(left.Elements_2D[i][1] * right.Elements_2D[1][j]);
				}
			}

			return result;
		}

		mat2f operator/(mat2f &left, float right)
		{
			mat2f result;

			for (unsigned int i = 0; i < 4; i++)
			{
				result.Elements_1D[i] = left.Elements_1D[i] / right;
			}

			return result;
		}
	}
}