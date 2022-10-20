/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file matrix3x3.h
*/
#pragma once
#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#ifndef MATRIX3x3_OFILB 
#define MATRIX3x3_OFILB
#include "ofilb/vec3.h"

namespace oi {

	template<typename T>
	struct tmat3 {
	public:
		// constructors 
		tmat3() : value{} {}
		explicit tmat3(const T& t) { this->value[0] = tvec3<T>(t, 0, 0); this->value[1] = tvec3<T>(0, t, 0); this->value[2] = tvec3<T>(0, 0, t); }
		tmat3(const T& x0, const T& y0, const T& z0, 
			  const T& x1, const T& y1, const T& z1,
			  const T& x2, const T& y2, const T& z2) { this->value[0] = tvec3<T>(x0, y0, z0); this->value[1] = tvec3<T>(x1, y1, z1); this->value[2] = tvec3<T>(x2, y2, z2); }
		
		tmat3(const tvec3<T>& v0, const tvec3<T>& v1, tvec3<T> v2) : value{ v0, v1, v2 } {};
		tmat3(const tmat3&) = default;

	private:
		tvec3<T> value[3];
	public:
		tmat3<T>& operator= (const tmat3& o);

		// operators
		const tmat3<T>& operator+= (const T& t);
		const tmat3<T>& operator+= (const tmat3& o);

		const tmat3<T>& operator-= (const T& t);
		const tmat3<T>& operator-= (const tmat3& o);

		const tmat3<T>& operator*= (const T& t);

		const tmat3<T>& operator/= (const T& t);

		tvec3<T>& operator[] (const uint32_t& i);
		const tvec3<T>& operator[] (const uint32_t& i) const;

		template<typename c>
		operator tmat3<c>();
	};

	// operator +
	template<typename type>
	tmat3<type> operator+ (const tmat3<type>& m, type t);

	template<typename T>
	tmat3<T> operator+ (const T& t, tmat3<T> m);

	template<typename type>
	tmat3<type> operator+ (const tmat3<type>& m, tmat3<type> o);

	// operator -
	template<typename T>
	tmat3<T> operator- (const tmat3<T>& m, T t);

	template<typename T>
	tmat3<T> operator- (const T& t, tmat3<T> m);

	template<typename T>
	tmat3<T> operator- (const tmat3<T>& m, tmat3<T> o);

	template<typename T>
	tmat3<T> operator- (const tmat3<T>& m);

	// operator *
	template<typename T>
	tmat3<T> operator* (const tmat3<T>& m, T t);

	template<typename T>
	tmat3<T> operator* (const T& t, const tmat3<T> m);

	template<typename T>
	tmat3<T> operator* (const tmat3<T>& m, tmat3<T> o);

	template<typename T>
	tvec3<T> operator* (const tmat3<T>& m, tvec3<T> v);

	// operator /
	template<typename T>
	tmat3<T> operator/ (const tmat3<T>& m, T t);

	template<typename T>
	tmat3<T> operator/ (const T& t, const tmat3<T> m);

	// functions
	template<typename T>
	tmat3<T> transpose(const tmat3<T>& m);

	template<typename T>
	tmat3<T> cofactor(const tmat3<T>& m);

	template<typename T>
	tmat3<T> adjoint(const tmat3<T>& m);

	template<typename T>
	T determinant(const tmat3<T>& m);

	template<typename T>
	tmat3<T> inverse(const tmat3<T>& m);

	template<typename T>
	T* value_ptr(tmat3<T>& m);
}

#include "ofilb/matrix3x3.inl"
#endif // MATRIX2x2 OFILB
