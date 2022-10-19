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
#define VECTOR3_OFILB

#include <ofilb/vec2.h>

namespace oi
{
	template <typename T>
	struct tvec3 {
		// constructors
		tvec3() : x(), y(), z() {}
		explicit tvec3(const T& _xyz) : x(_xyz), y(_xyz), z(_xyz) {}
		tvec3(const T& _x, const T& _y, T _z) : x(_x), y(_y), z(_z) {}
		tvec3(const tvec3&) = default;
		//tvec3(const tvec4<T>& v) : x(v.x), y(v.y), z(v.z) {}

		tvec3& operator= (const tvec3& o);

		// operators
		const tvec3& operator+= (const T& t);
		const tvec3& operator+= (const tvec3& o);

		const tvec3& operator-= (const T& t);
		const tvec3& operator-= (const tvec3& o);

		const tvec3& operator*= (const T& t);
		const tvec3& operator*= (const tvec3& o);

		const tvec3& operator/= (const T& t);

		T& operator[] (const uint32_t& i);
		const T& operator[] (const uint32_t& i) const;

		template<typename c>
		operator tvec3<c>();

		template<typename c>
		operator tvec2<c>();

		union
		{
			struct { T x, y, z; };

			struct { T r, g, b; };

			struct { T u, v, w; };
		};
	};

	// operator +
	template<typename T>
	tvec3<T> operator+(const tvec3<T>&v, tvec3<T> u);

	template<typename T>
	tvec3<T> operator+(const tvec3<T>& v, T t);

	template<typename T>
	tvec3<T> operator+(const T& t, tvec3<T> v);

	// operator -
	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v, tvec3<T> u);

	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v, T t);

	template<typename T>
	tvec3<T> operator-(const T& t, tvec3<T> v);

	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v);

	// operator *
	template<typename T>
	tvec3<T> operator*(const tvec3<T>& v, tvec3<T> u);

	template<typename T>
	tvec3<T> operator*(const tvec3<T>& v, T t);

	template<typename T>
	tvec3<T> operator*(const T& t, tvec3<T> v);

	// operator /
	template<typename T>
	tvec3<T> operator/(const tvec3<T>& v, T t);

	template<typename T>
	tvec3<T> operator/(const T& t, tvec3<T> v);

	// functions
	template<typename T>
	T length(const tvec3<T>& v);

	template<typename T>
	tvec3<T> normalize(const tvec3<T>& o);

	template<typename T>
	T* value_ptr(tvec3<T>& v);

} // namespace oi

#include "ofilb/vec3.inl"
#endif // VECTOR2 OFILB