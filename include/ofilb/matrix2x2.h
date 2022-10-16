/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file matrix2x2.h
*/
#pragma once
#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#ifndef MATRIX2x2_OFILB 
#define MATRIX2x2_OFILB
#include "ofilb/vec2.h"

namespace oi {

	template<typename T>
	struct tmat2 {
	public:
		// constructors 
		tmat2() : value{} {}
		explicit tmat2(const T& t) { this->value[0] = tvec2<T>(t, 0); this->value[1] = tvec2<T>(0, t); }
		tmat2(const T& x0, const T& y0, const T& x1, T y1) { this->value[0] = tvec2<T>(x0, y0); this->value[1] = tvec2<T>(x1, y1); }
		tmat2(const tvec2<T>& v0, tvec2<T> v1) : value{v0, v1} {};
		tmat2(const tmat2&) = default;

	private:
		tvec2<T> value[2];
	public:
		tmat2<T>& operator= (const tmat2& o);

		// operators
		const tmat2<T>& operator+= (const T& t);
		const tmat2<T>& operator+= (const tmat2& o);

		const tmat2<T>& operator-= (const T& t);
		const tmat2<T>& operator-= (const tmat2& o);

		const tmat2<T>& operator*= (const T& t);
		const tmat2<T>& operator*= (const tmat2& o);

		const tmat2<T>& operator/= (const T& t);
		
		tvec2<T>& operator[] (const uint32_t& i);
		const tvec2<T>& operator[] (const uint32_t& i) const;

		template<typename C>
		operator tmat2<C> ();
	};

	// operator +
	template<typename type>
	tmat2<type> operator+ (const tmat2<type>& m, type t);

	template<typename T>
	tmat2<T> operator+ (const T& t, tmat2<T> m);

	template<typename type>
	tmat2<type> operator+ (const tmat2<type>& m, tmat2<type> o);

	// operator -
	template<typename T>
	tmat2<T> operator- (const tmat2<T>& m, T t);

	template<typename T>
	tmat2<T> operator- (const T& t, tmat2<T> m);

	template<typename T>
	tmat2<T> operator- (const tmat2<T>& m, tmat2<T> o);

	template<typename T>
	tmat2<T> operator- (const tmat2<T>& m);

	// operator *
	template<typename T>
	tmat2<T> operator* (const tmat2<T>& m, T t);

	template<typename T>
	tmat2<T> operator* (const T& t, const tmat2<T> m);

	template<typename T>
	tmat2<T> operator* (const tmat2<T>& m, tmat2<T> o);

	// operator /
	template<typename T>
	tmat2<T> operator/ (const tmat2<T>& m, T t);

	template<typename T>
	tmat2<T> operator/ (const T& t, const tmat2<T> m);

	// functions
	template<typename T>
	tmat2<T> transpose(const tmat2<T>& m);
	
	template<typename T>
	T determinantof(const tmat2<T>& m);

	template<typename T>
	tmat2<T> inverse(const tmat2<T>& m);

	template<typename T>
	T* value_ptr(tmat2<T>& m);
}

#include "ofilb/matrix2x2.inl"
#endif // MATRIX2x2 OFILB
