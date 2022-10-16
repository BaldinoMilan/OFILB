/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file vec3.h
*/
#pragma once
#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#ifndef VECTOR3_OFILB
#define VECTOR2_OFILB

namespace oi
{
	template <typename T>
	struct tvec3 {

		tvec3() : x(), y(), z() {}
		explicit tvec3(const T& _xyz) : x(_xyz), y(_xyz), z(_xyz) {}
		tvec3(const T& _x, const T& _y, T _z) : x(_x), y(_y), z(_z) {}
		tvec3(const tvec3&) = default;

		tvec3& operator= (const tvec3& o);

		const tvec3& operator+= (const T& t);
		const tvec3& operator+= (const tvec3& o);

		const tvec3& operator-= (const T& t);
		const tvec3& operator-= (const tvec3& o);

		const tvec3& operator*= (const T& t);
		const tvec3& operator*= (const tvec3& o);

		const tvec3& operator/= (const T& t);
		const tvec3& operator/= (const tvec3& o);

		T& operator[] (const uint32_t& i);
		const T& operator[] (const uint32_t& i) const;

		template<typename C>
		operator tvec3<C>();

		union
		{
			struct { T x, y, z; };

			struct { T r, g, b; };

			struct { T u, v, w; };
		};
	};

	template<typename T>
	tvec3<T> operator+(const tvec3<T>&v, tvec3<T> u);
	template<typename T>
	tvec3<T> operator+(const tvec3<T>& v, T t);
	template<typename T>
	tvec3<T> operator+(const T& t, tvec3<T> v);

	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v, tvec3<T> u);
	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v, T t);
	template<typename T>
	tvec3<T> operator-(const T& t, tvec3<T> v);
	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v);

	template<typename T>
	tvec3<T> operator*(const tvec3<T>& v, tvec3<T> u);
	template<typename T>
	tvec3<T> operator*(const tvec3<T>& v, T t);

	template<typename T>
	tvec3<T> operator/(const tvec3<T>& v, tvec3<T> u);
	template<typename T>
	tvec3<T> operator/(const tvec3<T>& v, T t);

	template<typename T>
	T length(const tvec3<T>& v);

	template<typename T>
	tvec3<T> normalize(const tvec3<T>& o);

} // namespace oi

#include "ofilb/vec3.inl"
#endif // VECTOR2 OFILB