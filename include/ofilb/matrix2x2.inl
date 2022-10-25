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
#endif

namespace oi {
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec2<T>& tmat2<T>::operator[] (const uint32_t& i) noexcept
	{
		return value[i];
	}

	template<typename T>
	inline
	const tvec2<T>& tmat2<T>::operator[] (const uint32_t& i) const noexcept
	{
		return value[i];
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline 
	tmat2<T>& tmat2<T>::operator=(const tmat2<T>& o) noexcept
	{
		this->value[0] = o.value[0];
		this->value[1] = o.value[1];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline 
	const tmat2<T>& tmat2<T>::operator+=(const T& t) noexcept
	{
		this->value[0] += t;
		this->value[1] += t;
		return *this;
	}

	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator+=(const tmat2<T>& o) noexcept
	{
		this->value[0] += o.value[0];
		this->value[1] += o.value[1];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator-=(const T& t) noexcept
	{
		this->value[0] -= t;
		this->value[1] -= t;
		return *this;
	}

	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator-=(const tmat2<T>& o) noexcept
	{
		this->value[0] -= o.value[0];
		this->value[1] -= o.value[1];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator*=(const T& t) noexcept
	{
		this->value[0] *= t;
		this->value[1] *= t;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat2<T>& tmat2<T>::operator/=(const T& t) noexcept
	{
		this->value[0] /= t;
		this->value[1] /= t;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	template<typename c>
	inline tmat2<T>::operator tmat2<c>() noexcept
	{
		return tmat2<c>((tvec2<c>)value[0], (tvec2<c>)value[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator+ (const tmat2<T>& m, T t)  noexcept
	{
		return tmat2<T>(m[0] + t, m[1] + t);
	}

	template<typename T>
	inline
	tmat2<T> operator+ (const T& t, tmat2<T> m) noexcept
	{
		return tmat2<T>(m[0] + t, m[1] + t);
	}

	template<typename T>
	inline
	tmat2<T> operator+ (const tmat2<T>& m, tmat2<T> o) noexcept
	{
		return tmat2<T>(m[0] + o[0], m[1] + o[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m, T t) noexcept
	{
		return tmat2<T>(m[0] - t, m[1] - t);
	}

	template<typename T>
	inline
	tmat2<T> operator- (const T& t, tmat2<T> m) noexcept
	{
		return tmat2<T>(t - m[0], t - m[1]);
	}

	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m, tmat2<T> o) noexcept
	{
		return tmat2<T>(m[0] - o[0], m[1] - o[1]);
	}
	
	template<typename T>
	inline
	tmat2<T> operator- (const tmat2<T>& m) noexcept
	{
		return tmat2<T>(-m[0], -m[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator* (const tmat2<T>& m, T t) noexcept
	{
		return tmat2<T>(m[0] * t, m[1] * t);
	}

	template<typename T>
	inline
	tmat2<T> operator* (const T& t, tmat2<T> m) noexcept
	{
		return tmat2<T>(m[0] * t, m[1] * t);
	}

	template<typename T>
	inline
	tmat2<T> operator* (const tmat2<T>& o, tmat2<T> m) noexcept
	{
		return tmat2<T>(m[0][0]*o[0][0] + m[1][0]*o[0][1],   
						m[0][1]*o[0][0] + m[1][1]*o[0][1],
						m[0][0]*o[1][0] + m[1][0]*o[1][1],   
						m[0][1]*o[1][0] + m[1][1]*o[1][1]);
	}

	template<typename T>
	inline 
	tvec2<T> operator* (const tmat2<T>& m, tvec2<T> v) noexcept
	{
		return tvec2<T>(v.x * m[0][0] + v.y * m[0][1],
						v.x * m[1][0] + v.y * m[1][1]);
	}

	template<typename T>
	inline
	tvec2<T> operator* (const tvec2<T>& v, tmat2<T> m) noexcept
	{
		return tvec2<T>(v.x * m[0][0] + v.y * m[1][0],
						v.x * m[0][1] + v.y * m[1][1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> operator/ (const tmat2<T>& m, T t) noexcept
	{
		return tmat2<T>(m[0] / t, m[1] / t);
	}

	template<typename T>
	inline
	tmat2<T> operator/ (const T& t, tmat2<T> m) noexcept
	{
		return tmat2<T>(t / m[0], t / m[1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> transpose(const tmat2<T>& m) noexcept
	{
		return tmat2<T>(m[0][0], m[1][0], m[0][1], m[1][1]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline 
	tmat2<T> adjugate(const tmat2<T>& m) noexcept
	{
		return tmat2<T>(m[1][1], -m[0][1], -m[1][0], m[0][0]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> cofactor(const tmat2<T>& m) noexcept
	{
		return tmat2<T>(m[1][1], -m[1][0], -m[0][1], m[0][0]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T determinant(const tmat2<T>& m) noexcept
	{
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat2<T> inverse(const tmat2<T>& m) noexcept
	{
		return ((T)1.0 / determinant(m)) * tmat2<T>(m[1][1], -m[0][1], -m[1][0], m[0][0]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	T* value_ptr(tmat2<T>& m) noexcept
	{
		return &(m[0][0]);
	}
// ---------------------------------------------------------------------------

}