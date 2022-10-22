/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file matrix3x3.inl
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
	tvec3<T>& tmat3<T>::operator[] (const uint32_t& i)
	{
		return value[i];
	}

	template<typename T>
	inline
	const tvec3<T>& tmat3<T>::operator[] (const uint32_t& i) const
	{
		return value[i];
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat3<T>& tmat3<T>::operator=(const tmat3<T>& o)
	{
		this->value[0] = o.value[0];
		this->value[1] = o.value[1];
		this->value[2] = o.value[2];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat3<T>& tmat3<T>::operator+=(const T& t)
	{
		this->value[0] += t;
		this->value[1] += t;
		this->value[2] += t;
		return *this;
	}

	template<typename T>
	inline
	const tmat3<T>& tmat3<T>::operator+=(const tmat3<T>& o)
	{
		this->value[0] += o.value[0];
		this->value[1] += o.value[1];
		this->value[2] += o.value[2];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat3<T>& tmat3<T>::operator-=(const T& t)
	{
		this->value[0] -= t;
		this->value[1] -= t;
		this->value[2] -= t;
		return *this;
	}

	template<typename T>
	inline
	const tmat3<T>& tmat3<T>::operator-=(const tmat3<T>& o)
	{
		this->value[0] -= o.value[0];
		this->value[1] -= o.value[1];
		this->value[2] -= o.value[2];
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat3<T>& tmat3<T>::operator*=(const T& t)
	{
		this->value[0] *= t;
		this->value[1] *= t;
		this->value[2] *= t;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat3<T>& tmat3<T>::operator/=(const T& t)
	{
		this->value[0] /= t;
		this->value[1] /= t;
		this->value[2] /= t;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	template<typename c>
	inline 
	tmat3<T>::operator tmat3<c>()
	{
		return tmat3<c>((tvec3<c>)value[0], (tvec3<c>)value[1], (tvec3<c>)value[2]);
	}

	template<typename T>
	inline
	tmat3<T>::operator tmat2<T>()
	{
		return tmat2<T>(tvec2<T>(value[0]), tvec2<T>(value[1]));
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat3<T> operator+ (const tmat3<T>& m, T t)
	{
		return tmat3<T>(m[0] + t, m[1] + t, m[2] + t);
	}

	template<typename T>
	inline
	tmat3<T> operator+ (const T& t, tmat3<T> m)
	{
		return tmat3<T>(m[0] + t, m[1] + t, m[2] + t);
	}

	template<typename T>
	inline
	tmat3<T> operator+ (const tmat3<T>& m, tmat3<T> o)
	{
		return tmat3<T>(m[0] + o[0], m[1] + o[1], m[2] + o[2]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat3<T> operator- (const tmat3<T>& m, T t)
	{
		return tmat3<T>(m[0] - t, m[1] - t, m[2] - t);
	}

	template<typename T>
	inline
	tmat3<T> operator- (const T& t, tmat3<T> m)
	{
		return tmat3<T>(t - m[0], t - m[1], t - m[2]);
	}

	template<typename T>
	inline
	tmat3<T> operator- (const tmat3<T>& m, tmat3<T> o)
	{
		return tmat3<T>(m[0] - o[0], m[1] - o[1], m[2] - o[2]);
	}

	template<typename T>
	inline
	tmat3<T> operator- (const tmat3<T>& m)
	{
		return tmat3<T>(-m[0], -m[1], -m[2]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat3<T> operator* (const tmat3<T>& m, T t)
	{
		return tmat3<T>(m[0] * t, m[1] * t, m[2] * t);
	}

	template<typename T>
	inline
	tmat3<T> operator* (const T& t, tmat3<T> m)
	{
		return tmat3<T>(m[0] * t, m[1] * t, m[2] * t);
	}

	template<typename T>
	inline
	tmat3<T> operator* (const tmat3<T>& o, tmat3<T> m)
	{	
		return tmat3<T>(m[0][0] * o[0][0] + m[1][0] * o[0][1] + m[2][0] * o[0][2],
						m[0][1] * o[0][0] + m[1][1] * o[0][1] + m[2][1] * o[0][2],
						m[0][2] * o[0][0] + m[1][2] * o[0][1] + m[2][2] * o[0][2],

						m[0][0] * o[1][0] + m[1][0] * o[1][1] + m[2][0] * o[1][2],
						m[0][1] * o[1][0] + m[1][1] * o[1][1] + m[2][1] * o[1][2],
						m[0][2] * o[1][0] + m[1][2] * o[1][1] + m[2][2] * o[1][2],

						m[0][0] * o[2][0] + m[1][0] * o[2][1] + m[2][0] * o[2][2],
						m[0][1] * o[2][0] + m[1][1] * o[2][1] + m[2][1] * o[2][2],
						m[0][2] * o[2][0] + m[1][2] * o[2][1] + m[2][2] * o[2][2]);
	}

	template<typename T>
	inline
	tvec3<T> operator* (const tmat3<T>& m, tvec3<T> v)
	{
		return tvec3<T>(v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2],
						v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2],
						v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2]);
	}

	template<typename T>
	inline
	tvec3<T> operator* (const tvec3<T>& v, tmat3<T> m)
	{
		return tvec3<T>(v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0],
						v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1],
						v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat3<T> operator/ (const tmat3<T>& m, T t)
	{
		return tmat3<T>(m[0] / t, m[1] / t, m[2] / t);
	}

	template<typename T>
	inline
	tmat3<T> operator/ (const T& t, tmat3<T> m)
	{
		return tmat3<T>(t / m[0], t / m[1], t / m[2]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat3<T> transpose(const tmat3<T>& m)
	{
		return tmat3<T>(m[0][0], m[1][0], m[2][0], 
						m[0][1], m[1][1], m[2][1],
						m[0][2], m[1][2], m[2][2]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	tmat3<T> cofactor(const tmat3<T>& m)
	{
		return tmat3<T>((m[1][1] * m[2][2] - m[1][2] * m[2][1]), -(m[1][0] * m[2][2] - m[1][2] * m[2][0]), (m[1][0] * m[2][1] - m[1][1] * m[2][0]),
					   
					   -(m[0][1] * m[2][2] - m[0][2] * m[2][1]), (m[0][0] * m[2][2] - m[0][2] * m[2][0]), -(m[0][0] * m[2][1] - m[0][1] * m[2][0]),
					
						(m[0][1] * m[1][2] - m[0][2] * m[1][1]), -(m[0][0] * m[1][2] - m[0][2] * m[1][0]), (m[0][0] * m[1][1] - m[0][1] * m[1][0]));
	}
// ---------------------------------------------------------------------------

	template<typename T>
	tmat3<T> adjoint(const tmat3<T>& m)
	{
		return tmat3<T>((m[1][1] * m[2][2] - m[1][2] * m[2][1]), -(m[0][1] * m[2][2] - m[0][2] * m[2][1]), (m[0][1] * m[1][2] - m[0][2] * m[1][1]),
					   -(m[1][0] * m[2][2] - m[1][2] * m[2][0]),  (m[0][0] * m[2][2] - m[0][2] * m[2][0]),-(m[0][0] * m[1][2] - m[0][2] * m[1][0]),
						(m[1][0] * m[2][1] - m[1][1] * m[2][0]), -(m[0][0] * m[2][1] - m[0][1] * m[2][0]), (m[0][0] * m[1][1] - m[0][1] * m[1][0]));
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T determinant(const tmat3<T>& m)
	{
		return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
			 - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) 
			 + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat3<T> inverse(const tmat3<T>& m)
	{
		return ((T)1.0 / determinant(m)) * adjoint(m);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	T* value_ptr(tmat3<T>& m)
	{
		return &(m[0][0]);
	}
// ---------------------------------------------------------------------------

}