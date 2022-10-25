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
		explicit tmat2(const T& t) noexcept { this->value[0] = tvec2<T>(t, 0); 
											  this->value[1] = tvec2<T>(0, t); }
		
		tmat2(const T& x0, const T& y0, const T& x1, T y1) noexcept { this->value[0] = tvec2<T>(x0, y0); 
															          this->value[1] = tvec2<T>(x1, y1); }
		tmat2(const tvec2<T>& v0, tvec2<T> v1) noexcept : value{v0, v1} {};
		tmat2(const tmat2&) = default;

	private:
		tvec2<T> value[2];
	public:
		tmat2<T>& operator= (const tmat2& o) noexcept;

		// operators
		const tmat2<T>& operator+= (const T& t) noexcept;
		const tmat2<T>& operator+= (const tmat2& o) noexcept;

		const tmat2<T>& operator-= (const T& t) noexcept;
		const tmat2<T>& operator-= (const tmat2& o) noexcept;

		const tmat2<T>& operator*= (const T& t) noexcept;
	
		const tmat2<T>& operator/= (const T& t) noexcept;
		
		tvec2<T>& operator[] (const uint32_t& i) noexcept;
		const tvec2<T>& operator[] (const uint32_t& i) const noexcept;

		template<typename c>
		operator tmat2<c> () noexcept;
	};

	// operator +
	template<typename type>
	tmat2<type> operator+ (const tmat2<type>& m, type t) noexcept;

	template<typename T>
	tmat2<T> operator+ (const T& t, tmat2<T> m) noexcept;

	template<typename type>
	tmat2<type> operator+ (const tmat2<type>& m, tmat2<type> o) noexcept;

	// operator -
	template<typename T>
	tmat2<T> operator- (const tmat2<T>& m, T t) noexcept;

	template<typename T>
	tmat2<T> operator- (const T& t, tmat2<T> m) noexcept;

	template<typename T>
	tmat2<T> operator- (const tmat2<T>& m, tmat2<T> o) noexcept;

	template<typename T>
	tmat2<T> operator- (const tmat2<T>& m) noexcept;

	// operator *
	template<typename T>
	tmat2<T> operator* (const tmat2<T>& m, T t) noexcept;

	template<typename T>
	tmat2<T> operator* (const T& t, const tmat2<T> m) noexcept;

	template<typename T>
	tmat2<T> operator* (const tmat2<T>& m, tmat2<T> o) noexcept;

	template<typename T>
	tvec2<T> operator* (const tmat2<T>& m, tvec2<T> v) noexcept;

	// operator /
	template<typename T>
	tmat2<T> operator/ (const tmat2<T>& m, T t) noexcept;

	template<typename T>
	tmat2<T> operator/ (const T& t, const tmat2<T> m) noexcept;

	// functions
	template<typename T>
	tmat2<T> transpose(const tmat2<T>& m) noexcept;
	
	template<typename T>
	tmat2<T> adjugate(const tmat2<T>& m) noexcept;

	template<typename T>
	tmat2<T> cofactor(const tmat2<T>& m) noexcept;

	template<typename T>
	T determinant(const tmat2<T>& m) noexcept;

	template<typename T>
	tmat2<T> inverse(const tmat2<T>& m) noexcept;

	template<typename T>
	T* value_ptr(tmat2<T>& m) noexcept;
}

#include "ofilb/matrix2x2.inl"
#endif // MATRIX2x2 OFILB
