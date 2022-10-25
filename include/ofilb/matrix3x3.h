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
#include "ofilb/matrix2x2.h"

namespace oi {

	template<typename T>
	struct tmat3 {
	public:
		// constructors 
		tmat3() noexcept : value{} {}
		explicit tmat3(const T& t)  noexcept
		{ 
			this->value[0] = tvec3<T>(t, 0, 0); 
			this->value[1] = tvec3<T>(0, t, 0); 
			this->value[2] = tvec3<T>(0, 0, t); 
		}

		tmat3(const T& x0, const T& y0, const T& z0, 
			  const T& x1, const T& y1, const T& z1,
			  const T& x2, const T& y2, T z2)  noexcept 
		
		{ 
			this->value[0] = tvec3<T>(x0, y0, z0);
			this->value[1] = tvec3<T>(x1, y1, z1); 
			this->value[2] = tvec3<T>(x2, y2, z2); 
		}
		
		tmat3(const tvec3<T>& v0, const tvec3<T>& v1, tvec3<T> v2) noexcept : value{ v0, v1, v2 } {};
		tmat3(const tmat3&) = default;

	private:
		tvec3<T> value[3];
	public:
		tmat3<T>& operator= (const tmat3& o)  noexcept;

		// operators
		const tmat3<T>& operator+= (const T& t)  noexcept;
		const tmat3<T>& operator+= (const tmat3& o)  noexcept;

		const tmat3<T>& operator-= (const T& t)  noexcept;
		const tmat3<T>& operator-= (const tmat3& o) noexcept;

		const tmat3<T>& operator*= (const T& t) noexcept;

		const tmat3<T>& operator/= (const T& t) noexcept;

		tvec3<T>& operator[] (const uint32_t& i) noexcept;
		const tvec3<T>& operator[] (const uint32_t& i) const noexcept;

		template<typename c>
		operator tmat3<c>() noexcept;

		operator tmat2<T>() noexcept;
	};

	// operator +
	template<typename type>
	tmat3<type> operator+ (const tmat3<type>& m, type t) noexcept;

	template<typename T>
	tmat3<T> operator+ (const T& t, tmat3<T> m) noexcept;

	template<typename type>
	tmat3<type> operator+ (const tmat3<type>& m, tmat3<type> o) noexcept;

	// operator -
	template<typename T>
	tmat3<T> operator- (const tmat3<T>& m, T t) noexcept;

	template<typename T>
	tmat3<T> operator- (const T& t, tmat3<T> m) noexcept;

	template<typename T>
	tmat3<T> operator- (const tmat3<T>& m, tmat3<T> o) noexcept;

	template<typename T>
	tmat3<T> operator- (const tmat3<T>& m) noexcept;

	// operator *
	template<typename T>
	tmat3<T> operator* (const tmat3<T>& m, T t) noexcept;

	template<typename T>
	tmat3<T> operator* (const T& t, const tmat3<T> m) noexcept;

	template<typename T>
	tmat3<T> operator* (const tmat3<T>& m, tmat3<T> o) noexcept;

	template<typename T>
	tvec3<T> operator* (const tmat3<T>& m, tvec3<T> v) noexcept;

	// operator /
	template<typename T>
	tmat3<T> operator/ (const tmat3<T>& m, T t) noexcept;

	template<typename T>
	tmat3<T> operator/ (const T& t, const tmat3<T> m) noexcept;

	// functions
	template<typename T>
	tmat3<T> transpose(const tmat3<T>& m) noexcept;

	template<typename T>
	tmat3<T> cofactor(const tmat3<T>& m) noexcept;

	template<typename T>
	tmat3<T> adjugate(const tmat3<T>& m) noexcept;

	template<typename T>
	T determinant(const tmat3<T>& m) noexcept;

	template<typename T>
	tmat3<T> inverse(const tmat3<T>& m) noexcept;

	template<typename T>
	T* value_ptr(tmat3<T>& m) noexcept;
}

#include "ofilb/matrix3x3.inl"
#endif // MATRIX3x3 OFILB
