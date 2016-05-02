#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		namespace Functions
		{
			template<typename T>
			T Clamp(T value, T min, T max)
			{
				if (value < min)
				{
					return min;
				}
				else if (value > max)
				{
					return max;
				}
				else
				{
					return value;
				}
			}

			template<typename T>
			void Swap(T &a, T &b)
			{
				T temp = a;
				a = b;
				b = temp;
			}
		}
	}
}