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

#include <ofilb/vec2.h>
#include <ofilb/vec3.h>

namespace oi
{
	template <typename T>
	struct tvec4 {
		// constructors
		tvec4() noexcept : x(), y(), z(), w() {}
		explicit tvec4(const T& _xyzw) noexcept : x(_xyzw), y(_xyzw), z(_xyzw), w(_xyzw) {}
		tvec4(const T& _x, const T& _y, const T& _z, T _w) noexcept : x(_x), y(_y), z(_z), w(_w) {}
		tvec4(const tvec4&) = default;

		tvec4& operator= (const tvec4& o) noexcept;

		// operators
		const tvec4& operator+= (const T& t) noexcept;
		const tvec4& operator+= (const tvec4& o) noexcept;

		const tvec4& operator-= (const T& t) noexcept;
		const tvec4& operator-= (const tvec4& o) noexcept;


		const tvec4& operator*= (const T& t) noexcept;
		const tvec4& operator*= (const tvec4& o) noexcept;

		const tvec4& operator/= (const T& t) noexcept;

		T& operator[] (const uint32_t& i) noexcept;
		const T& operator[] (const uint32_t& i) const noexcept;

		template<typename c>
		operator tvec4<c>() noexcept;

		template<typename c>
		operator tvec2<c>() noexcept;

		template<typename c>
		operator tvec3<c>() noexcept;

		union
		{
			struct { T x, y, z, w; };

			struct { T r, g, b, a; };
		};
	};

	// operator +
	template<typename T>
	tvec4<T> operator+(const tvec4<T>& v, tvec4<T> u) noexcept;
	
	template<typename T>
	tvec4<T> operator+(const tvec4<T>& v, T t) noexcept;
	
	template<typename T>
	tvec4<T> operator+(const T& t, tvec4<T> v) noexcept;
	
	// operator -
	template<typename T>
	tvec4<T> operator-(const tvec4<T>& v, tvec4<T> u) noexcept;
	
	template<typename T>
	tvec4<T> operator-(const tvec4<T>& v, T t) noexcept;
	
	template<typename T>
	tvec4<T> operator-(const T& t, tvec4<T> v) noexcept;
	
	template<typename T>
	tvec4<T> operator-(const tvec4<T>& v) noexcept;

	// operator *
	template<typename T>
	tvec4<T> operator*(const tvec4<T>& v, tvec4<T> u) noexcept;
	
	template<typename T>
	tvec4<T> operator*(const tvec4<T>& v, T t) noexcept;

	template<typename T>
	tvec4<T> operator*(const T& t, tvec4<T> v) noexcept;

	// operator /
	template<typename T>
	tvec4<T> operator/(const tvec4<T>& v, T t) noexcept;

	template<typename T>
	tvec4<T> operator/(const T& t, tvec4<T> v) noexcept;

	// functions
	template<typename T>
	T length(const tvec4<T>& v) noexcept;

	template<typename T>
	tvec4<T> normalize(const tvec4<T>& o) noexcept;

	template<typename T>
	T* value_ptr(tvec4<T>& v) noexcept;

} // namespace oi

#include "ofilb/vec4.inl"
#endif // VECTOR4 OFILB