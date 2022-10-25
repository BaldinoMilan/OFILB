/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file matrix4x4.h
*/
#pragma once
#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#ifndef MATRIX4x4_OFILB 
#define MATRIX4x4_OFILB
#include "ofilb/vec4.h"
#include "ofilb/matrix2x2.h"
#include "ofilb/matrix3x3.h"

namespace oi {

	template<typename T>
	struct tmat4 {
	public:
		// constructors 
		tmat4() : value{} {}
		explicit tmat4(const T& t) noexcept
		{ 
			this->value[0] = tvec4<T>(t, 0, 0, 0); 
			this->value[1] = tvec4<T>(0, t, 0, 0); 
			this->value[2] = tvec4<T>(0, 0, t, 0);
			this->value[3] = tvec4<T>(0, 0, 0, t); 
		}

		tmat4(const T& x0, const T& y0, const T& z0, const T& w0,
			  const T& x1, const T& y1, const T& z1, const T& w1,
			  const T& x2, const T& y2, const T& z2, const T& w2,
			  const T& x3, const T& y3, const T& z3, T w3) noexcept
		{
			this->value[0] = tvec4<T>(x0, y0, z0, w0); 
			this->value[1] = tvec4<T>(x1, y1, z1, w1); 
			this->value[2] = tvec4<T>(x2, y2, z2, w2);
			this->value[3] = tvec4<T>(x3, y3, z3, w3);
		}

		tmat4(const tvec4<T>& v0, const tvec4<T>& v1, const tvec4<T>& v2, tvec4<T> v3) noexcept : value{ v0, v1, v2, v3 } {};
		tmat4(const tmat4&) = default;

	private:
		tvec4<T> value[4];
	public:
		tmat4<T>& operator= (const tmat4& o) noexcept;

		// operators
		const tmat4<T>& operator+= (const T& t) noexcept;
		const tmat4<T>& operator+= (const tmat4& o) noexcept;

		const tmat4<T>& operator-= (const T& t) noexcept;
		const tmat4<T>& operator-= (const tmat4& o) noexcept;

		const tmat4<T>& operator*= (const T& t) noexcept;

		const tmat4<T>& operator/= (const T& t) noexcept;

		tvec4<T>& operator[] (const uint32_t& i) noexcept;
		const tvec4<T>& operator[] (const uint32_t& i) const noexcept;

		template<typename c>
		operator tmat4<c>() noexcept;

		operator tmat2<T>() noexcept;
		operator tmat3<T>() noexcept;
	};

	// operator +
	template<typename type>
	tmat4<type> operator+ (const tmat4<type>& m, type t) noexcept;

	template<typename T>
	tmat4<T> operator+ (const T& t, tmat4<T> m) noexcept;

	template<typename type>
	tmat4<type> operator+ (const tmat4<type>& m, tmat4<type> o) noexcept;

	// operator -
	template<typename T>
	tmat4<T> operator- (const tmat4<T>& m, T t) noexcept;

	template<typename T>
	tmat4<T> operator- (const T& t, tmat4<T> m) noexcept;

	template<typename T>
	tmat4<T> operator- (const tmat4<T>& m, tmat4<T> o) noexcept;

	template<typename T>
	tmat4<T> operator- (const tmat4<T>& m) noexcept;

	// operator *
	template<typename T>
	tmat4<T> operator* (const tmat4<T>& m, T t) noexcept;

	template<typename T>
	tmat4<T> operator* (const T& t, const tmat4<T> m) noexcept;

	template<typename T>
	tmat4<T> operator* (const tmat4<T>& m, tmat4<T> o) noexcept;

	template<typename T>
	tvec4<T> operator* (const tmat4<T>& m, tvec4<T> v) noexcept;

	// operator /
	template<typename T>
	tmat4<T> operator/ (const tmat4<T>& m, T t) noexcept;

	template<typename T>
	tmat4<T> operator/ (const T& t, const tmat4<T> m) noexcept;

	// functions
	template<typename T>
	tmat4<T> transpose(const tmat4<T>& m) noexcept;

	template<typename T>
	tmat4<T> cofactor(const tmat4<T>& m) noexcept;

	template<typename T>
	tmat4<T> adjugate(const tmat4<T>& m) noexcept;

	template<typename T>
	T determinant(const tmat4<T>& m) noexcept;

	template<typename T>
	tmat4<T> inverse(const tmat4<T>& m) noexcept;

	template<typename T>
	T* value_ptr(tmat4<T>& m) noexcept;
}

#include "ofilb/matrix4x4.inl"
#endif // MATRIX4x4 OFILB

