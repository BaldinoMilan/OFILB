/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file vec4.h
*/
#pragma once
#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#ifndef VECTOR4_OFILB
#define VECTOR4_OFILB

namespace oi
{
	template <typename T>
	struct tvec4 {

		tvec4() : x(), y(), z() {}
		explicit tvec4(const T& _xyzw) : x(_xyzw), y(_xyzw), z(_xyzw), w(_xyzw) {}
		tvec4(const T& _x, const T& _y, const T& _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
		tvec4(const tvec4&) = default;

		tvec4& operator= (const tvec4& o);

		const tvec4& operator+= (const T& t);
		const tvec4& operator+= (const tvec4& o);

		const tvec4& operator-= (const T& t);
		const tvec4& operator-= (const tvec4& o);

		const tvec4& operator*= (const T& t);
		const tvec4& operator*= (const tvec4& o);

		const tvec4& operator/= (const T& t);
		const tvec4& operator/= (const tvec4& o);

		T& operator[] (const uint32_t& i);
		const T& operator[] (const uint32_t& i) const;

		template<typename C>
		operator tvec4<C>();

		union
		{
			struct { T x, y, z, w; };

			struct { T r, g, b, a; };
		};
	};

	template<typename T>
	tvec4<T> operator+(const tvec4<T>& v, tvec4<T> u);
	template<typename T>
	tvec4<T> operator+(const tvec4<T>& v, T t);

	template<typename T>
	tvec4<T> operator-(const tvec4<T>& v, tvec4<T> u);
	template<typename T>
	tvec4<T> operator-(const tvec4<T>& v, T t);
	template<typename T>
	tvec4<T> operator-(const T& t, tvec4<T> v);
	template<typename T>
	tvec4<T>  operator-(const tvec4<T>& v);

	template<typename T>
	tvec4<T> operator*(const tvec4<T>& v, tvec4<T> u);
	template<typename T>
	tvec4<T> operator*(const tvec4<T>& v, T t);

	template<typename T>
	tvec4<T> operator/(const tvec4<T>& v, tvec4<T> u);
	template<typename T>
	tvec4<T> operator/(const tvec4<T>& v, T t);

	template<typename T>
	T length(const tvec4<T>& v);

	template<typename T>
	tvec4<T> normalize(const tvec4<T>& o);

} // namespace oi

#include "ofilb/vec4.inl"
#endif // VECTOR4 OFILB