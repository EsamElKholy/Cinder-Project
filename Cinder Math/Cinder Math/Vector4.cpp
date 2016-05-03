#ifndef VECTOR4_CPP
#define VECTOR4_CPP

#include "CinderMath.h"

namespace Cinder
{
	namespace Math
	{
		template<class T>
		Vector4<T>::Vector4(T x, T y, T z, T w)
			: X(x), Y(y), Z(z), W(w)
		{}

		template<class T>
		Vector4<T>::Vector4(Vector3<T> &vec3, T w)
			: X(vec3.X), Y(vec3.Y), Z(vec3.z), W(w)
		{}

		template<class T>
		Vector4<T>::Vector4(T x, Vector3<T> &vec3)
			: X(x), Y(vec3.X), Z(vec3.Y), W(vec3.Z)
		{}

		template<class T>
		Vector4<T>::Vector4(Vector3<T> &vec3)
			: X(vec3.X), Y(vec3.Y), Z(vec3.z), W(T(0))
		{}

		template<class T>
		Vector4<T>::Vector4(Vector2<T> &vec2)
			: X(vec2.X), Y(vec2.Y), Z(T(0)), W(T(0))
		{}

		template<class T>
		Vector4<T>::Vector4(Vector2<T> &vec2_1, Vector2<T> &vec2_2)
			: X(vec2_1.X), Y(vec2_1.Y), Z(vec2_2.X), W(vec2_2.Y)
		{}

		template<class T>
		Vector4<T>::Vector4(Vector2<T> &vec2, T z, T w)
			: X(vec2.X), Y(vec2.Y), Z(z), W(w)
		{}

		template<class T>
		Vector4<T>::Vector4(T x, T y, Vector2<T> &vec2)
			: X(x), Y(y), Z(vec2.X), W(vec2.Y)
		{}

		//////////////////////					

		template<class T>
		Vector2<T> Vector4<T>::XX()
		{
			return Vector2<T>(this->X, this->X);
		}

		template<class T>
		Vector2<T> Vector4<T>::XY()
		{
			return Vector2<T>(this->X, this->Y);
		}

		template<class T>
		Vector2<T> Vector4<T>::XZ()
		{
			return Vector2<T>(this->X, this->Z);
		}

		template<class T>
		Vector2<T> Vector4<T>::XW()
		{
			return Vector2<T>(this->X, this->W);
		}

		//////////////////////

		template<class T>
		Vector2<T> Vector4<T>::YX()
		{
			return Vector2<T>(this->Y, this->X);
		}

		template<class T>
		Vector2<T> Vector4<T>::YY()
		{
			return Vector2<T>(this->Y, this->Y);
		}

		template<class T>
		Vector2<T> Vector4<T>::YZ()
		{
			return Vector2<T>(this->Y, this->Z);
		}

		template<class T>
		Vector2<T> Vector4<T>::YW()
		{
			return Vector2<T>(this->Y, this->W);
		}

		//////////////////////

		template<class T>
		Vector2<T> Vector4<T>::ZX()
		{
			return Vector2<T>(this->Z, this->X);
		}

		template<class T>
		Vector2<T> Vector4<T>::ZY()
		{
			return Vector2<T>(this->Z, this->Y);
		}

		template<class T>
		Vector2<T> Vector4<T>::ZZ()
		{
			return Vector2<T>(this->Z, this->Z);
		}

		template<class T>
		Vector2<T> Vector4<T>::ZW()
		{
			return Vector2<T>(this->Z, this->W);
		}

		///////////////////////

		template<class T>
		Vector2<T> Vector4<T>::WX()
		{
			return Vector2<T>(this->W, this->X);
		}

		template<class T>
		Vector2<T> Vector4<T>::WY()
		{
			return Vector2<T>(this->W, this->Y);
		}

		template<class T>
		Vector2<T> Vector4<T>::WZ()
		{
			return Vector2<T>(this->W, this->Z);
		}

		template<class T>
		Vector2<T> Vector4<T>::WW()
		{
			return Vector2<T>(this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector3<T> Vector4<T>::XXX()
		{
			return Vector3<T>(this->X, this->X, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::XXY()
		{
			return Vector3<T>(this->X, this->X, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::XXZ()
		{
			return Vector3<T>(this->X, this->X, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::XXW()
		{
			return Vector3<T>(this->X, this->X, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::XYX()
		{
			return Vector3<T>(this->X, this->Y, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::XYY()
		{
			return Vector3<T>(this->X, this->Y, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::XYZ()
		{
			return Vector3<T>(this->X, this->Y, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::XYW()
		{
			return Vector3<T>(this->X, this->Y, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::XZX()
		{
			return Vector3<T>(this->X, this->Z, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::XZY()
		{
			return Vector3<T>(this->X, this->Z, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::XZZ()
		{
			return Vector3<T>(this->X, this->Z, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::XZW()
		{
			return Vector3<T>(this->X, this->Z, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::XWX()
		{
			return Vector3<T>(this->X, this->W, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::XWY()
		{
			return Vector3<T>(this->X, this->W, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::XWZ()
		{
			return Vector3<T>(this->X, this->W, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::XWW()
		{
			return Vector3<T>(this->X, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector3<T> Vector4<T>::YXX()
		{
			return Vector3<T>(this->Y, this->X, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::YXY()
		{
			return Vector3<T>(this->Y, this->X, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::YXZ()
		{
			return Vector3<T>(this->Y, this->X, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::YXW()
		{
			return Vector3<T>(this->Y, this->X, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::YYX()
		{
			return Vector3<T>(this->Y, this->Y, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::YYY()
		{
			return Vector3<T>(this->Y, this->Y, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::YYZ()
		{
			return Vector3<T>(this->Y, this->Y, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::YYW()
		{
			return Vector3<T>(this->Y, this->Y, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::YZX()
		{
			return Vector3<T>(this->Y, this->Z, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::YZY()
		{
			return Vector3<T>(this->Y, this->Z, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::YZZ()
		{
			return Vector3<T>(this->Y, this->Z, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::YZW()
		{
			return Vector3<T>(this->Y, this->Z, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::YWX()
		{
			return Vector3<T>(this->Y, this->W, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::YWY()
		{
			return Vector3<T>(this->Y, this->W, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::YWZ()
		{
			return Vector3<T>(this->Y, this->W, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::YWW()
		{
			return Vector3<T>(this->Y, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector3<T> Vector4<T>::ZXX()
		{
			return Vector3<T>(this->Z, this->X, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZXY()
		{
			return Vector3<T>(this->Z, this->X, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZXZ()
		{
			return Vector3<T>(this->Z, this->X, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZXW()
		{
			return Vector3<T>(this->Z, this->X, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZYX()
		{
			return Vector3<T>(this->Z, this->Y, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZYY()
		{
			return Vector3<T>(this->Z, this->Y, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZYZ()
		{
			return Vector3<T>(this->Z, this->Y, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZYW()
		{
			return Vector3<T>(this->Z, this->Y, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZZX()
		{
			return Vector3<T>(this->Z, this->Z, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZZY()
		{
			return Vector3<T>(this->Z, this->Z, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZZZ()
		{
			return Vector3<T>(this->Z, this->Z, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZZW()
		{
			return Vector3<T>(this->Z, this->Z, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZWX()
		{
			return Vector3<T>(this->Z, this->W, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZWY()
		{
			return Vector3<T>(this->Z, this->W, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZWZ()
		{
			return Vector3<T>(this->Z, this->W, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::ZWW()
		{
			return Vector3<T>(this->Z, this->W, this->W);
		}

		//////////////////////	

		template<class T>
		Vector3<T> Vector4<T>::WXX()
		{
			return Vector3<T>(this->W, this->X, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::WXY()
		{
			return Vector3<T>(this->W, this->X, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::WXZ()
		{
			return Vector3<T>(this->W, this->X, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::WXW()
		{
			return Vector3<T>(this->W, this->X, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::WYX()
		{
			return Vector3<T>(this->W, this->Y, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::WYY()
		{
			return Vector3<T>(this->W, this->Y, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::WYZ()
		{
			return Vector3<T>(this->W, this->Y, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::WYW()
		{
			return Vector3<T>(this->W, this->Y, this->W);
		}

		template<class T>
		Vector3<T> Vector4<T>::WZX()
		{
			return Vector3<T>(this->W, this->Z, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::WZY()
		{
			return Vector3<T>(this->W, this->Z, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::WZZ()
		{
			return Vector3<T>(this->W, this->Z, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::WZW()
		{
			return Vector3<T>(this->W, this->Z, this->W);
		}


		template<class T>
		Vector3<T> Vector4<T>::WWX()
		{
			return Vector3<T>(this->W, this->W, this->X);
		}

		template<class T>
		Vector3<T> Vector4<T>::WWY()
		{
			return Vector3<T>(this->W, this->W, this->Y);
		}

		template<class T>
		Vector3<T> Vector4<T>::WWZ()
		{
			return Vector3<T>(this->W, this->W, this->Z);
		}

		template<class T>
		Vector3<T> Vector4<T>::WWW()
		{
			return Vector3<T>(this->W, this->W, this->W);
		}

		//////////////////////
		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::XXXX()
		{
			return Vector4<T>(this->X, this->X, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXXY()
		{
			return Vector4<T>(this->X, this->X, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXXZ()
		{
			return Vector4<T>(this->X, this->X, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXXW()
		{
			return Vector4<T>(this->X, this->X, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXYX()
		{
			return Vector4<T>(this->X, this->X, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXYY()
		{
			return Vector4<T>(this->X, this->X, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXYZ()
		{
			return Vector4<T>(this->X, this->X, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXYW()
		{
			return Vector4<T>(this->X, this->X, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXZX()
		{
			return Vector4<T>(this->X, this->X, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXZY()
		{
			return Vector4<T>(this->X, this->X, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXZZ()
		{
			return Vector4<T>(this->X, this->X, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXZW()
		{
			return Vector4<T>(this->X, this->X, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXWX()
		{
			return Vector4<T>(this->X, this->X, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXWY()
		{
			return Vector4<T>(this->X, this->X, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXWZ()
		{
			return Vector4<T>(this->X, this->X, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XXWW()
		{
			return Vector4<T>(this->X, this->X, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::XYXX()
		{
			return Vector4<T>(this->X, this->Y, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYXY()
		{
			return Vector4<T>(this->X, this->Y, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYXZ()
		{
			return Vector4<T>(this->X, this->Y, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYXW()
		{
			return Vector4<T>(this->X, this->Y, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYYX()
		{
			return Vector4<T>(this->X, this->Y, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYYY()
		{
			return Vector4<T>(this->X, this->Y, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYYZ()
		{
			return Vector4<T>(this->X, this->Y, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYYW()
		{
			return Vector4<T>(this->X, this->Y, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYZX()
		{
			return Vector4<T>(this->X, this->Y, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYZY()
		{
			return Vector4<T>(this->X, this->Y, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYZZ()
		{
			return Vector4<T>(this->X, this->Y, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYZW()
		{
			return Vector4<T>(this->X, this->Y, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYWX()
		{
			return Vector4<T>(this->X, this->Y, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYWY()
		{
			return Vector4<T>(this->X, this->Y, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYWZ()
		{
			return Vector4<T>(this->X, this->Y, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XYWW()
		{
			return Vector4<T>(this->X, this->Y, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::XZXX()
		{
			return Vector4<T>(this->X, this->Z, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZXY()
		{
			return Vector4<T>(this->X, this->Z, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZXZ()
		{
			return Vector4<T>(this->X, this->Z, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZXW()
		{
			return Vector4<T>(this->X, this->Z, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZYX()
		{
			return Vector4<T>(this->X, this->Z, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZYY()
		{
			return Vector4<T>(this->X, this->Z, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZYZ()
		{
			return Vector4<T>(this->X, this->Z, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZYW()
		{
			return Vector4<T>(this->X, this->Z, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZZX()
		{
			return Vector4<T>(this->X, this->Z, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZZY()
		{
			return Vector4<T>(this->X, this->Z, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZZZ()
		{
			return Vector4<T>(this->X, this->Z, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZZW()
		{
			return Vector4<T>(this->X, this->Z, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZWX()
		{
			return Vector4<T>(this->X, this->Z, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZWY()
		{
			return Vector4<T>(this->X, this->Z, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZWZ()
		{
			return Vector4<T>(this->X, this->Z, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XZWW()
		{
			return Vector4<T>(this->X, this->Z, this->W, this->W);
		}

		//////////////////////	

		template<class T>
		Vector4<T> Vector4<T>::XWXX()
		{
			return Vector4<T>(this->X, this->W, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWXY()
		{
			return Vector4<T>(this->X, this->W, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWXZ()
		{
			return Vector4<T>(this->X, this->W, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWXW()
		{
			return Vector4<T>(this->X, this->W, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWYX()
		{
			return Vector4<T>(this->X, this->W, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWYY()
		{
			return Vector4<T>(this->X, this->W, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWYZ()
		{
			return Vector4<T>(this->X, this->W, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWYW()
		{
			return Vector4<T>(this->X, this->W, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWZX()
		{
			return Vector4<T>(this->X, this->W, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWZY()
		{
			return Vector4<T>(this->X, this->W, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWZZ()
		{
			return Vector4<T>(this->X, this->W, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWZW()
		{
			return Vector4<T>(this->X, this->W, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWWX()
		{
			return Vector4<T>(this->X, this->W, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWWY()
		{
			return Vector4<T>(this->X, this->W, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWWZ()
		{
			return Vector4<T>(this->X, this->W, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::XWWW()
		{
			return Vector4<T>(this->X, this->W, this->W, this->W);
		}

		//////////////////////
		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::YXXX()
		{
			return Vector4<T>(this->Y, this->X, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXXY()
		{
			return Vector4<T>(this->Y, this->X, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXXZ()
		{
			return Vector4<T>(this->Y, this->X, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXXW()
		{
			return Vector4<T>(this->Y, this->X, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXYX()
		{
			return Vector4<T>(this->Y, this->X, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXYY()
		{
			return Vector4<T>(this->Y, this->X, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXYZ()
		{
			return Vector4<T>(this->Y, this->X, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXYW()
		{
			return Vector4<T>(this->Y, this->X, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXZX()
		{
			return Vector4<T>(this->Y, this->X, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXZY()
		{
			return Vector4<T>(this->Y, this->X, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXZZ()
		{
			return Vector4<T>(this->Y, this->X, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXZW()
		{
			return Vector4<T>(this->Y, this->X, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXWX()
		{
			return Vector4<T>(this->Y, this->X, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXWY()
		{
			return Vector4<T>(this->Y, this->X, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXWZ()
		{
			return Vector4<T>(this->Y, this->X, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YXWW()
		{
			return Vector4<T>(this->Y, this->X, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::YYXX()
		{
			return Vector4<T>(this->Y, this->Y, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYXY()
		{
			return Vector4<T>(this->Y, this->Y, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYXZ()
		{
			return Vector4<T>(this->Y, this->Y, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYXW()
		{
			return Vector4<T>(this->Y, this->Y, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYYX()
		{
			return Vector4<T>(this->Y, this->Y, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYYY()
		{
			return Vector4<T>(this->Y, this->Y, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYYZ()
		{
			return Vector4<T>(this->Y, this->Y, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYYW()
		{
			return Vector4<T>(this->Y, this->Y, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYZX()
		{
			return Vector4<T>(this->Y, this->Y, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYZY()
		{
			return Vector4<T>(this->Y, this->Y, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYZZ()
		{
			return Vector4<T>(this->Y, this->Y, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYZW()
		{
			return Vector4<T>(this->Y, this->Y, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYWX()
		{
			return Vector4<T>(this->Y, this->Y, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYWY()
		{
			return Vector4<T>(this->Y, this->Y, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYWZ()
		{
			return Vector4<T>(this->Y, this->Y, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YYWW()
		{
			return Vector4<T>(this->Y, this->Y, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::YZXX()
		{
			return Vector4<T>(this->Y, this->Z, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZXY()
		{
			return Vector4<T>(this->Y, this->Z, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZXZ()
		{
			return Vector4<T>(this->Y, this->Z, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZXW()
		{
			return Vector4<T>(this->Y, this->Z, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZYX()
		{
			return Vector4<T>(this->Y, this->Z, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZYY()
		{
			return Vector4<T>(this->Y, this->Z, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZYZ()
		{
			return Vector4<T>(this->Y, this->Z, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZYW()
		{
			return Vector4<T>(this->Y, this->Z, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZZX()
		{
			return Vector4<T>(this->Y, this->Z, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZZY()
		{
			return Vector4<T>(this->Y, this->Z, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZZZ()
		{
			return Vector4<T>(this->Y, this->Z, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZZW()
		{
			return Vector4<T>(this->Y, this->Z, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZWX()
		{
			return Vector4<T>(this->Y, this->Z, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZWY()
		{
			return Vector4<T>(this->Y, this->Z, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZWZ()
		{
			return Vector4<T>(this->Y, this->Z, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YZWW()
		{
			return Vector4<T>(this->Y, this->Z, this->W, this->W);
		}

		//////////////////////	

		template<class T>
		Vector4<T> Vector4<T>::YWXX()
		{
			return Vector4<T>(this->Y, this->W, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWXY()
		{
			return Vector4<T>(this->Y, this->W, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWXZ()
		{
			return Vector4<T>(this->Y, this->W, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWXW()
		{
			return Vector4<T>(this->Y, this->W, this->X, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::YWYX()
		{
			return Vector4<T>(this->Y, this->W, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWYY()
		{
			return Vector4<T>(this->Y, this->W, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWYZ()
		{
			return Vector4<T>(this->Y, this->W, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWYW()
		{
			return Vector4<T>(this->Y, this->W, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWZX()
		{
			return Vector4<T>(this->Y, this->W, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWZY()
		{
			return Vector4<T>(this->Y, this->W, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWZZ()
		{
			return Vector4<T>(this->Y, this->W, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWZW()
		{
			return Vector4<T>(this->Y, this->W, this->Z, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::YWWX()
		{
			return Vector4<T>(this->Y, this->W, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWWY()
		{
			return Vector4<T>(this->Y, this->W, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWWZ()
		{
			return Vector4<T>(this->Y, this->W, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::YWWW()
		{
			return Vector4<T>(this->Y, this->W, this->W, this->W);
		}


		//////////////////////
		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::ZXXX()
		{
			return Vector4<T>(this->Z, this->X, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXXY()
		{
			return Vector4<T>(this->Z, this->X, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXXZ()
		{
			return Vector4<T>(this->Z, this->X, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXXW()
		{
			return Vector4<T>(this->Z, this->X, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXYX()
		{
			return Vector4<T>(this->Z, this->X, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXYY()
		{
			return Vector4<T>(this->Z, this->X, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXYZ()
		{
			return Vector4<T>(this->Z, this->X, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXYW()
		{
			return Vector4<T>(this->Z, this->X, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXZX()
		{
			return Vector4<T>(this->Z, this->X, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXZY()
		{
			return Vector4<T>(this->Z, this->X, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXZZ()
		{
			return Vector4<T>(this->Z, this->X, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXZW()
		{
			return Vector4<T>(this->Z, this->X, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXWX()
		{
			return Vector4<T>(this->Z, this->X, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXWY()
		{
			return Vector4<T>(this->Z, this->X, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXWZ()
		{
			return Vector4<T>(this->Z, this->X, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZXWW()
		{
			return Vector4<T>(this->Z, this->X, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::ZYXX()
		{
			return Vector4<T>(this->Z, this->Y, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYXY()
		{
			return Vector4<T>(this->Z, this->Y, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYXZ()
		{
			return Vector4<T>(this->Z, this->Y, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYXW()
		{
			return Vector4<T>(this->Z, this->Y, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYYX()
		{
			return Vector4<T>(this->Z, this->Y, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYYY()
		{
			return Vector4<T>(this->Z, this->Y, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYYZ()
		{
			return Vector4<T>(this->Z, this->Y, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYYW()
		{
			return Vector4<T>(this->Z, this->Y, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYZX()
		{
			return Vector4<T>(this->Z, this->Y, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYZY()
		{
			return Vector4<T>(this->Z, this->Y, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYZZ()
		{
			return Vector4<T>(this->Z, this->Y, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYZW()
		{
			return Vector4<T>(this->Z, this->Y, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYWX()
		{
			return Vector4<T>(this->Z, this->Y, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYWY()
		{
			return Vector4<T>(this->Z, this->Y, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYWZ()
		{
			return Vector4<T>(this->Z, this->Y, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZYWW()
		{
			return Vector4<T>(this->Z, this->Y, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::ZZXX()
		{
			return Vector4<T>(this->Z, this->Z, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZXY()
		{
			return Vector4<T>(this->Z, this->Z, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZXZ()
		{
			return Vector4<T>(this->Z, this->Z, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZXW()
		{
			return Vector4<T>(this->Z, this->Z, this->X, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::ZZYX()
		{
			return Vector4<T>(this->Z, this->Z, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZYY()
		{
			return Vector4<T>(this->Z, this->Z, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZYZ()
		{
			return Vector4<T>(this->Z, this->Z, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZYW()
		{
			return Vector4<T>(this->Z, this->Z, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZZX()
		{
			return Vector4<T>(this->Z, this->Z, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZZY()
		{
			return Vector4<T>(this->Z, this->Z, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZZZ()
		{
			return Vector4<T>(this->Z, this->Z, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZZW()
		{
			return Vector4<T>(this->Z, this->Z, this->Z, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::ZZWX()
		{
			return Vector4<T>(this->Z, this->Z, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZWY()
		{
			return Vector4<T>(this->Z, this->Z, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZWZ()
		{
			return Vector4<T>(this->Z, this->Z, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZZWW()
		{
			return Vector4<T>(this->Z, this->Z, this->W, this->W);
		}

		//////////////////////	

		template<class T>
		Vector4<T> Vector4<T>::ZWXX()
		{
			return Vector4<T>(this->Z, this->W, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWXY()
		{
			return Vector4<T>(this->Z, this->W, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWXZ()
		{
			return Vector4<T>(this->Z, this->W, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWXW()
		{
			return Vector4<T>(this->Z, this->W, this->X, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::ZWYX()
		{
			return Vector4<T>(this->Z, this->W, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWYY()
		{
			return Vector4<T>(this->Z, this->W, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWYZ()
		{
			return Vector4<T>(this->Z, this->W, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWYW()
		{
			return Vector4<T>(this->Z, this->W, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWZX()
		{
			return Vector4<T>(this->Z, this->W, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWZY()
		{
			return Vector4<T>(this->Z, this->W, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWZZ()
		{
			return Vector4<T>(this->Z, this->W, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWZW()
		{
			return Vector4<T>(this->Z, this->W, this->Z, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::ZWWX()
		{
			return Vector4<T>(this->Z, this->W, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWWY()
		{
			return Vector4<T>(this->Z, this->W, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWWZ()
		{
			return Vector4<T>(this->Z, this->W, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::ZWWW()
		{
			return Vector4<T>(this->Z, this->W, this->W, this->W);
		}

		//////////////////////
		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::WXXX()
		{
			return Vector4<T>(this->W, this->X, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXXY()
		{
			return Vector4<T>(this->W, this->X, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXXZ()
		{
			return Vector4<T>(this->W, this->X, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXXW()
		{
			return Vector4<T>(this->W, this->X, this->X, this->W);
		}



		template<class T>
		Vector4<T> Vector4<T>::WXYX()
		{
			return Vector4<T>(this->W, this->X, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXYY()
		{
			return Vector4<T>(this->W, this->X, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXYZ()
		{
			return Vector4<T>(this->W, this->X, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXYW()
		{
			return Vector4<T>(this->W, this->X, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXZX()
		{
			return Vector4<T>(this->W, this->X, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXZY()
		{
			return Vector4<T>(this->W, this->X, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXZZ()
		{
			return Vector4<T>(this->W, this->X, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXZW()
		{
			return Vector4<T>(this->W, this->X, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXWX()
		{
			return Vector4<T>(this->W, this->X, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXWY()
		{
			return Vector4<T>(this->W, this->X, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXWZ()
		{
			return Vector4<T>(this->W, this->X, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WXWW()
		{
			return Vector4<T>(this->W, this->X, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::WYXX()
		{
			return Vector4<T>(this->W, this->Y, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYXY()
		{
			return Vector4<T>(this->W, this->Y, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYXZ()
		{
			return Vector4<T>(this->W, this->Y, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYXW()
		{
			return Vector4<T>(this->W, this->Y, this->X, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYYX()
		{
			return Vector4<T>(this->W, this->Y, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYYY()
		{
			return Vector4<T>(this->W, this->Y, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYYZ()
		{
			return Vector4<T>(this->W, this->Y, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYYW()
		{
			return Vector4<T>(this->W, this->Y, this->Y, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYZX()
		{
			return Vector4<T>(this->W, this->Y, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYZY()
		{
			return Vector4<T>(this->W, this->Y, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYZZ()
		{
			return Vector4<T>(this->W, this->Y, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYZW()
		{
			return Vector4<T>(this->W, this->Y, this->Z, this->W);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYWX()
		{
			return Vector4<T>(this->W, this->Y, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYWY()
		{
			return Vector4<T>(this->W, this->Y, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYWZ()
		{
			return Vector4<T>(this->W, this->Y, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WYWW()
		{
			return Vector4<T>(this->W, this->Y, this->W, this->W);
		}

		//////////////////////

		template<class T>
		Vector4<T> Vector4<T>::WZXX()
		{
			return Vector4<T>(this->W, this->Z, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZXY()
		{
			return Vector4<T>(this->W, this->Z, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZXZ()
		{
			return Vector4<T>(this->W, this->Z, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZXW()
		{
			return Vector4<T>(this->W, this->Z, this->X, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::WZYX()
		{
			return Vector4<T>(this->W, this->Z, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZYY()
		{
			return Vector4<T>(this->W, this->Z, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZYZ()
		{
			return Vector4<T>(this->W, this->Z, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZYW()
		{
			return Vector4<T>(this->W, this->Z, this->Y, this->W);
		}



		template<class T>
		Vector4<T> Vector4<T>::WZZX()
		{
			return Vector4<T>(this->W, this->Z, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZZY()
		{
			return Vector4<T>(this->W, this->Z, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZZZ()
		{
			return Vector4<T>(this->W, this->Z, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZZW()
		{
			return Vector4<T>(this->W, this->Z, this->Z, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::WZWX()
		{
			return Vector4<T>(this->W, this->Z, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZWY()
		{
			return Vector4<T>(this->W, this->Z, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZWZ()
		{
			return Vector4<T>(this->W, this->Z, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WZWW()
		{
			return Vector4<T>(this->W, this->Z, this->W, this->W);
		}

		//////////////////////	

		template<class T>
		Vector4<T> Vector4<T>::WWXX()
		{
			return Vector4<T>(this->W, this->W, this->X, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWXY()
		{
			return Vector4<T>(this->W, this->W, this->X, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWXZ()
		{
			return Vector4<T>(this->W, this->W, this->X, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWXW()
		{
			return Vector4<T>(this->W, this->W, this->X, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::WWYX()
		{
			return Vector4<T>(this->W, this->W, this->Y, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWYY()
		{
			return Vector4<T>(this->W, this->W, this->Y, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWYZ()
		{
			return Vector4<T>(this->W, this->W, this->Y, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWYW()
		{
			return Vector4<T>(this->W, this->W, this->Y, this->W);
		}



		template<class T>
		Vector4<T> Vector4<T>::WWZX()
		{
			return Vector4<T>(this->W, this->W, this->Z, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWZY()
		{
			return Vector4<T>(this->W, this->W, this->Z, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWZZ()
		{
			return Vector4<T>(this->W, this->W, this->Z, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWZW()
		{
			return Vector4<T>(this->W, this->W, this->Z, this->W);
		}


		template<class T>
		Vector4<T> Vector4<T>::WWWX()
		{
			return Vector4<T>(this->W, this->W, this->W, this->X);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWWY()
		{
			return Vector4<T>(this->W, this->W, this->W, this->Y);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWWZ()
		{
			return Vector4<T>(this->W, this->W, this->W, this->Z);
		}

		template<class T>
		Vector4<T> Vector4<T>::WWWW()
		{
			return Vector4<T>(this->W, this->W, this->W, this->W);
		}

		/////////////////////////////////////

		template<class T>
		void Vector4<T>::operator=(Vector4<T> &v4Right)
		{
			this->X = v4Right.X;
			this->Y = v4Right.Y;
			this->Z = v4Right.Z;
			this->W = v4Right.W;
		}

		template<class T>
		bool Vector4<T>::operator==(Vector4<T> &v4Right)
		{
			bool x = this->X == v4Right.X;
			bool y = this->Y == v4Right.Y;
			bool z = this->Z == v4Right.Z;
			bool w = this->W == v4Right.W;

			return x && y && z && w;
		}

		template<class T>
		bool Vector4<T>::operator!=(Vector4<T> &v4Right)
		{
			bool x = this->X != v4Right.X;
			bool y = this->Y != v4Right.Y;
			bool z = this->Z != v4Right.Z;
			bool w = this->W != v4Right.W;

			return x || y || z || w;
		}

		template<class T>
		T Vector4<T>::operator[](unsigned int index)
		{
			if (index >= 4)
			{
				index = 3;
			}

			return this->Elements[index];
		}


		////////////////////////////////////////////

		template<class T>
		void Vector4<T>::operator+=(Vector4<T> &v4Right)
		{
			*this = Vector4<T>(this->X + v4Right.X, this->Y + v4Right.Y, this->Z + v4Right.Z, this->W + v4Right.W);
		}

		template<class T>
		void Vector4<T>::operator-=(Vector4<T> &v4Right)
		{
			*this = Vector4<T>(this->X - v4Right.X, this->Y - v4Right.Y, this->Z - v4Right.Z, this->W - v4Right.W);
		}

		template<class T>
		void Vector4<T>::operator*=(Vector4<T> &v4Right)
		{
			*this = Vector4<T>(this->X * v4Right.X, this->Y * v4Right.Y, this->Z * v4Right.Z, this->W * v4Right.W);
		}

		template<class T>
		void Vector4<T>::operator/=(Vector4<T> &v4Right)
		{
			*this = Vector4<T>(this->X / v4Right.X, this->Y / v4Right.Y, this->Z / v4Right.Z, this->W / v4Right.W);
		}

		template<class T>
		void Vector4<T>::operator+=(T right)
		{
			*this = Vector4<T>(this->X + right, this->Y + right, this->Z + right, this->W + right);
		}

		template<class T>
		void Vector4<T>::operator-=(T right)
		{
			*this = Vector4<T>(this->X - right, this->Y - right, this->Z - right, this->W - right);
		}

		template<class T>
		void Vector4<T>::operator*=(T right)
		{
			*this = Vector4<T>(this->X * right, this->Y * right, this->Z * right, this->W * right);
		}

		template<class T>
		void Vector4<T>::operator/=(T right)
		{
			*this = Vector4<T>(this->X / right, this->Y / right, this->Z / right, this->W / right);
		}

		////////////////////////////////////////////

		/////////////

		template<typename T>
		Vector4<T> operator+(Vector4<T> &v4Left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Sum(v4Left, v4Right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator-(Vector4<T> &v4Left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Sub(v4Left, v4Right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator*(Vector4<T> &v4Left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Mul(v4Left, v4Right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator/(Vector4<T> &v4Left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Div(v4Left, v4Right);
			return v4Left;
		}


		template<typename T>
		Vector4<T> operator+(Vector4<T> &v4Left, T right)
		{
			v4Left = Vec4::Sum(v4Left, right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator-(Vector4<T> &v4Left, T right)
		{
			v4Left = Vec4::Sub(v4Left, right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator*(Vector4<T> &v4Left, T right)
		{
			v4Left = Vec4::Mul(v4Left, right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator/(Vector4<T> &v4Left, T right)
		{
			v4Left = Vec4::Div(v4Left, right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator+(T left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Sum(left, v4Right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator-(T left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Sub(left, v4Right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator*(T left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Mul(left, v4Right);
			return v4Left;
		}

		template<typename T>
		Vector4<T> operator/(T left, Vector4<T> &v4Right)
		{
			v4Left = Vec4::Div(left, v4Right);
			return v4Left;
		}

		/////////////////			

		namespace Vec4
		{
			template<typename T>
			float Length(Vector4<T> &v4)
			{
				float result = sqrtf((v4.X * v4.X) + (v4.Y * v4.Y) + (v4.Z * v4.Z) + (v4.W * v4.W));
				return result;
			}

			template<typename T>
			float LengthSquare(Vector4<T> &v4)
			{
				float result = ((v4.X * v4.X) + (v4.Y * v4.Y) + (v4.Z * v4.Z) + (v4.W * v4.W));
				return result;
			}

			template<typename T>
			Vector4<T> Normalize(Vector4<T> &v4)
			{
				float length = Length(v4);
				v4 = Vector4<T>((v4.X / length), (v4.Y / length), (v4.Z / length), (v4.W / length));
				return v4;
			}

			template<typename T>
			Vector4<T> Sum(Vector4<T> &v4Left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(v4Left.X + v4Right.X, v4Left.Y + v4Right.Y, v4Left.Z + v4Right.Z, v4Left.W + v4Right.W);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Sub(Vector4<T> &v4Left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(v4Left.X - v4Right.X, v4Left.Y - v4Right.Y, v4Left.Z - v4Right.Z, v4Left.W - v4Right.W);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Mul(Vector4<T> &v4Left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(v4Left.X * v4Right.X, v4Left.Y * v4Right.Y, v4Left.Z * v4Right.Z, v4Left.W * v4Right.W);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Div(Vector4<T> &v4Left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(v4Left.X / v4Right.X, v4Left.Y / v4Right.Y, v4Left.Z / v4Right.Z, v4Left.W / v4Right.W);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Sum(Vector4<T> &v4Left, T right)
			{
				v4Left = Vector4<T>(v4Left.X + right, v4Left.Y + right, v4Left.Z + right, v4Left.W + right);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Sub(Vector4<T> &v4Left, T right)
			{
				v4Left = Vector4<T>(v4Left.X - right, v4Left.Y - right, v4Left.Z - right, v4Left.W - right);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Mul(Vector4<T> &v4Left, T right)
			{
				v4Left = Vector4<T>(v4Left.X * right, v4Left.Y * right, v4Left.Z * right, v4Left.W * right);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Div(Vector4<T> &v4Left, T right)
			{
				v4Left = Vector4<T>(v4Left.X / right, v4Left.Y / right, v4Left.Z / right, v4Left.W / right);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Sum(T left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(left + v4Right.X, left + v4Right.Y, left + v4Right.Z, left + v4Right.W);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Sub(T left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(left - v4Right.X, left - v4Right.Y, left - v4Right.Z, left - v4Right.W);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Mul(T left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(left * v4Right.X, left * v4Right.Y, left * v4Right.Z, left * v4Right.W);
				return v4Left;
			}

			template<typename T>
			Vector4<T> Div(T left, Vector4<T> &v4Right)
			{
				v4Left = Vector4<T>(left / v4Right.X, left / v4Right.Y, left / v4Right.Z, left / v4Right.W);
				return v4Left;
			}			
		}
	}
}

#endif