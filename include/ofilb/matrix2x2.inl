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
// ---------------------------------------------------------------------------
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
// ---------------------------------------------------------------------------
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
// ---------------------------------------------------------------------------
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
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator*=(const tmat2<T>& o)
	{
		this->value[0] *= o.value[0];
		this->value[1] *= o.value[1];
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
	inline
	const tmat2<T>& tmat2<T>::operator/=(const tmat2<T>& o)
	{
		this->value[0] /= o.value[0];
		this->value[1] /= o.value[1];
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
		return tmat2<T>(m.value[0] + t, m.value[1] + t);
	}

	template<typename T>
	inline
	tmat2<T> operator+ (const T& t, tmat2<T> m)
	{
		return tmat2<T>(m.value[0] + t, m.value[1] + t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator+ (const tmat2<T>& m, tmat2<T> o)
	{
		return tmat2<T>(m.value[0] + o.value[0], m.value[1] + o.value[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m, T t)
	{
		return tmat2<T>(m.value[0] - t, m.value[1] - t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator- (const T& t, tmat2<T> m)
	{
		return tmat2<T>(t - m.value[0], t - m.value[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m, tmat2<T> o)
	{
		return tmat2<T>(m.value[0] - o.value[0], m.value[1] - o.value[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator* (const tmat2<T>& m, T t)
	{
		return tmat2<T>(m.value[0] * t, m.value[1] * t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator* (const T& t, tmat2<T> m)
	{
		return tmat2<T>(m.value[0] * t, m.value[1] * t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator* (const tmat2<T>& m, tmat2<T> o)
	{
		return tmat2<T>(m.value[0] * o.value[0], m.value[1] * o.value[1]);
	}
// ---------------------------------------------------------------------------

}