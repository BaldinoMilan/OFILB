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
		tvec2 () : x(), y() {}
		explicit tvec2 (const T& _xy) : x(_xy), y(_xy) {}
		tvec2 (const T& _x, T _y) : x(_x), y(_y) {}
		tvec2 (const tvec2&) = default;
		
		tvec2& operator= (const tvec2& o);

		// operators
		const tvec2& operator+= (const T& t);
		const tvec2& operator+= (const tvec2& o);

		const tvec2& operator-= (const T& t);
		const tvec2& operator-= (const tvec2& o);
		
		const tvec2& operator*= (const T& t);
		const tvec2& operator*= (const tvec2& o);

		const tvec2& operator/= (const T& t);
		
		T& operator[] (const uint32_t& i);
		const T& operator[] (const uint32_t& i) const;

		template<typename C>
		operator tvec2<C> ();

		union 
		{
			struct { T x, y; };

			struct { T u, v; };
		};
	};

	// operator +
	template<typename T>
	tvec2<T> operator+(const tvec2<T>& v, tvec2<T> u);
	
	template<typename T>
	tvec2<T> operator+(const tvec2<T>& v, T t);
	
	template<typename T>
	tvec2<T> operator+(const T& t, tvec2<T> v);

	// operator -
	template<typename T>
	tvec2<T> operator-(const tvec2<T>& v, tvec2<T> u);
	
	template<typename T>
	tvec2<T> operator-(const tvec2<T>& v, T t);
	
	template<typename T>
	tvec2<T> operator-(const T& t, tvec2<T> v);
	
	template<typename T>
	tvec2<T>  operator-(const tvec2<T>& v);

	// opeator *
	template<typename T>
	tvec2<T> operator*(const tvec2<T>& v, tvec2<T> u);
	
	template<typename T>
	tvec2<T> operator*(const tvec2<T>& v, T t);

	template<typename T>
	tvec2<T> operator*(const T& t, tvec2<T> v);

	// operator /
	template<typename T>
	tvec2<T> operator/(const tvec2<T>& v, T t);

	template<typename T>
	tvec2<T> operator/(const T& t, tvec2<T> v);

	// functions
	template<typename T>
	T length(const tvec2<T>& v);

	template<typename T>
	tvec2<T> normalize(const tvec2<T>& o);

	template<typename T>
	T* value_ptr(tvec2<T>& v);

} // namespace oi

#include "ofilb/vec2.inl"
#endif // VECTOR2 OFILB