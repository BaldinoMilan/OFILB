/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file vec2.h
*/

#pragma once
#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#ifndef VECTOR2_OFILB
#define VECTOR2_OFILB

namespace oi 
{
	template <typename T>
	struct tvec2 {
		// constructors
		tvec2 () noexcept : x(), y() {}
		explicit tvec2 (const T& _xy) noexcept : x(_xy), y(_xy) {}
		tvec2 (const T& _x, T _y) noexcept : x(_x), y(_y) {}
		tvec2 (const tvec2&) = default;
		
		tvec2& operator= (const tvec2& o) noexcept;

		// operators
		const tvec2& operator+= (const T& t) noexcept;
		const tvec2& operator+= (const tvec2& o) noexcept;

		const tvec2& operator-= (const T& t) noexcept;
		const tvec2& operator-= (const tvec2& o) noexcept;
		
		const tvec2& operator*= (const T& t) noexcept;
		const tvec2& operator*= (const tvec2& o) noexcept;

		const tvec2& operator/= (const T& t) noexcept;
		
		T& operator[] (const uint32_t& i) noexcept;
		const T& operator[] (const uint32_t& i) const noexcept;

		template<typename C>
		operator tvec2<C> () noexcept;

		union 
		{
			struct { T x, y; };

			struct { T u, v; };
		};
	};

	// operator +
	template<typename T>
	tvec2<T> operator+(const tvec2<T>& v, tvec2<T> u) noexcept;
	
	template<typename T>
	tvec2<T> operator+(const tvec2<T>& v, T t) noexcept;
	
	template<typename T>
	tvec2<T> operator+(const T& t, tvec2<T> v) noexcept;

	// operator -
	template<typename T>
	tvec2<T> operator-(const tvec2<T>& v, tvec2<T> u) noexcept;
	
	template<typename T>
	tvec2<T> operator-(const tvec2<T>& v, T t) noexcept;
	
	template<typename T>
	tvec2<T> operator-(const T& t, tvec2<T> v) noexcept;
	
	template<typename T>
	tvec2<T>  operator-(const tvec2<T>& v) noexcept;

	// opeator *
	template<typename T>
	tvec2<T> operator*(const tvec2<T>& v, tvec2<T> u) noexcept;
	
	template<typename T>
	tvec2<T> operator*(const tvec2<T>& v, T t) noexcept;

	template<typename T>
	tvec2<T> operator*(const T& t, tvec2<T> v) noexcept;

	// operator /
	template<typename T>
	tvec2<T> operator/(const tvec2<T>& v, T t) noexcept;

	template<typename T>
	tvec2<T> operator/(const T& t, tvec2<T> v) noexcept;

	// functions
	template<typename T>
	T length(const tvec2<T>& v) noexcept;

	template<typename T>
	tvec2<T> normalize(const tvec2<T>& o) noexcept;

	template<typename T>
	T* value_ptr(tvec2<T>& v) noexcept;

} // namespace oi

#include "ofilb/vec2.inl"
#endif // VECTOR2 OFILB