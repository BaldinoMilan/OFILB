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
		tvec3() noexcept : x(), y(), z() {}
		explicit tvec3(const T& _xyz) noexcept : x(_xyz), y(_xyz), z(_xyz) {}
		tvec3(const T& _x, const T& _y, T _z) noexcept : x(_x), y(_y), z(_z) {}
		tvec3(const tvec3&) = default;
		
		tvec3& operator= (const tvec3& o) noexcept;

		// operators
		const tvec3& operator+= (const T& t) noexcept;
		const tvec3& operator+= (const tvec3& o) noexcept;

		const tvec3& operator-= (const T& t) noexcept;
		const tvec3& operator-= (const tvec3& o) noexcept;

		const tvec3& operator*= (const T& t) noexcept;
		const tvec3& operator*= (const tvec3& o) noexcept;

		const tvec3& operator/= (const T& t) noexcept;

		T& operator[] (const uint32_t& i) noexcept;
		const T& operator[] (const uint32_t& i) const noexcept;

		template<typename c>
		operator tvec3<c>() noexcept;

		template<typename c>
		operator tvec2<c>() noexcept;

		union
		{
			struct { T x, y, z; };

			struct { T r, g, b; };

			struct { T u, v, w; };
		};
	};

	// operator +
	template<typename T>
	tvec3<T> operator+(const tvec3<T>&v, tvec3<T> u) noexcept;

	template<typename T>
	tvec3<T> operator+(const tvec3<T>& v, T t) noexcept;

	template<typename T>
	tvec3<T> operator+(const T& t, tvec3<T> v) noexcept;

	// operator -
	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v, tvec3<T> u) noexcept;

	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v, T t) noexcept;

	template<typename T>
	tvec3<T> operator-(const T& t, tvec3<T> v) noexcept;

	template<typename T>
	tvec3<T> operator-(const tvec3<T>& v) noexcept;

	// operator *
	template<typename T>
	tvec3<T> operator*(const tvec3<T>& v, tvec3<T> u) noexcept;

	template<typename T>
	tvec3<T> operator*(const tvec3<T>& v, T t) noexcept;

	template<typename T>
	tvec3<T> operator*(const T& t, tvec3<T> v) noexcept;

	// operator /
	template<typename T>
	tvec3<T> operator/(const tvec3<T>& v, T t) noexcept;

	template<typename T>
	tvec3<T> operator/(const T& t, tvec3<T> v) noexcept;

	// functions
	template<typename T>
	T length(const tvec3<T>& v) noexcept;

	template<typename T>
	tvec3<T> normalize(const tvec3<T>& o) noexcept;

	template<typename T>
	T* value_ptr(tvec3<T>& v) noexcept;

} // namespace oi

#include "ofilb/vec3.inl"
#endif // VECTOR2 OFILB