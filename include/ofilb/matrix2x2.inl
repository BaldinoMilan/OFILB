/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file matrix2x2.inl
*/

#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#include "matrix2x2.h"
#endif

namespace oi {
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec2<T>& tmat2<T>::operator[] (const uint32_t& i)
	{
		return value[i];
	}

	template<typename T>
	inline
	const tvec2<T>& tmat2<T>::operator[] (const uint32_t& i) const
	{
		return value[i];
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline 
	tmat2<T>& tmat2<T>::operator=(const tmat2<T>& o)
	{
		this->value[0] = o.value[0];
		this->value[1] = o.value[1];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline 
	const tmat2<T>& tmat2<T>::operator+=(const T& t)
	{
		this->value[0] += t;
		this->value[1] += t;
		return *this;
	}

	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator+=(const tmat2<T>& o)
	{
		this->value[0] += o.value[0];
		this->value[1] += o.value[1];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator-=(const T& t)
	{
		this->value[0] -= t;
		this->value[1] -= t;
		return *this;
	}

	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator-=(const tmat2<T>& o)
	{
		this->value[0] -= o.value[0];
		this->value[1] -= o.value[1];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator*=(const T& t)
	{
		this->value[0] *= t;
		this->value[1] *= t;
		return *this;
	}

	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator*=(const tmat2<T>& o)
	{
		this->value[0][0] = this->value[0][0] * o[0][0] + this->value[1][0] * o[0][1];
		this->value[0][1] = this->value[0][1] * o[0][0] + this->value[1][1] * o[0][1];
		this->value[1][0] = this->value[0][0] * o[1][0] + this->value[1][0] * o[1][1];
		this->value[1][1] = this->value[0][1] * o[1][0] + this->value[1][1] * o[1][1];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator/=(const T& t)
	{
		this->value[0] /= t;
		this->value[1] /= t;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	template<typename C>
	inline tmat2<T>::operator tmat2<C>()
	{
		return tmat2<C>((tvec2<C>)value[0], (tvec2<C>)value[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator+ (const tmat2<T>& m, T t) 
	{
		return tmat2<T>(m[0] + t, m[1] + t);
	}

	template<typename T>
	inline
	tmat2<T> operator+ (const T& t, tmat2<T> m)
	{
		return tmat2<T>(m[0] + t, m[1] + t);
	}

	template<typename T>
	inline
	tmat2<T> operator+ (const tmat2<T>& m, tmat2<T> o)
	{
		return tmat2<T>(m[0] + o[0], m[1] + o[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m, T t)
	{
		return tmat2<T>(m[0] - t, m[1] - t);
	}

	template<typename T>
	inline
	tmat2<T> operator- (const T& t, tmat2<T> m)
	{
		return tmat2<T>(t - m[0], t - m[1]);
	}

	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m, tmat2<T> o)
	{
		return tmat2<T>(m[0] - o[0], m[1] - o[1]);
	}
	
	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m)
	{
		return tmat2<T>(-m[0], -m[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator* (const tmat2<T>& m, T t)
	{
		return tmat2<T>(m[0] * t, m[1] * t);
	}

	template<typename T>
	inline
	tmat2<T> operator* (const T& t, tmat2<T> m)
	{
		return tmat2<T>(m[0] * t, m[1] * t);
	}

	template<typename T>
	inline
	tmat2<T> operator* (const tmat2<T>& m, tmat2<T> o)
	{
		return tmat2<T>(m[0][0]*o[0][0] + m[1][0]*o[0][1],   
						m[0][1]*o[0][0] + m[1][1]*o[0][1],
						m[0][0]*o[1][0] + m[1][0]*o[1][1],   
						m[0][1]*o[1][0] + m[1][1]*o[1][1]);
	}

	template<typename T>
	inline 
	tvec2<T> operator* (const tmat2<T>& m, tvec2<T> v)
	{
		return tvec2<T>(v.x * m[0][0] + v.y * m[1][0],
						v.x * m[0][1] + v.y * m[1][1]);
	}

	template<typename T>
	inline
	tvec2<T> operator* (const tvec2<T>& v, tmat2<T> m)
	{
		return tvec2<T>(v.x * m[0][0] + v.y * m[0][1],
						v.x * m[1][0] + v.y * m[1][1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator/ (const tmat2<T>& m, T t)
	{
		return tmat2<T>(m[0] / t, m[1] / t);
	}

	template<typename T>
	inline
	tmat2<T> operator/ (const T& t, tmat2<T> m)
	{
		return tmat2<T>(t / m[0], t / m[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> transpose(const tmat2<T>& m)
	{
		return tmat2<T>(m[0][0], m[1][0], m[0][1], m[1][1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T determinantof(const tmat2<T>& m)
	{
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> inverse(const tmat2<T>& m)
	{
		return ((T)1.0 / determinantof(m)) * tmat2<T>(m[1][1], -m[0][1], -m[1][0], m[0][0]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	T* value_ptr(tmat2<T>& m)
	{
		return &(m[0][0]);
	}
// ---------------------------------------------------------------------------

}