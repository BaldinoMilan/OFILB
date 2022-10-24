/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file matrix4x4.inl
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
	tvec4<T>& tmat4<T>::operator[] (const uint32_t& i) noexcept
	{
		return value[i];
	}

	template<typename T>
	inline
	const tvec4<T>& tmat4<T>::operator[] (const uint32_t& i) const noexcept
	{
		return value[i];
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat4<T>& tmat4<T>::operator=(const tmat4<T>& o) noexcept
	{
		this->value[0] = o.value[0];
		this->value[1] = o.value[1];
		this->value[2] = o.value[2];
		this->value[3] = o.value[3];
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat4<T>& tmat4<T>::operator+=(const T& t) noexcept
	{
		this->value[0] += t;
		this->value[1] += t;
		this->value[2] += t;
		this->value[4] += t;
		return *this;
	}

	template<typename T>
	inline
	const tmat4<T>& tmat4<T>::operator+=(const tmat4<T>& o) noexcept
	{
		this->value[0] += o.value[0];
		this->value[1] += o.value[1];
		this->value[2] += o.value[2];
		this->value[3] += o.value[3];
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat4<T>& tmat4<T>::operator-=(const T& t) noexcept
	{
		this->value[0] -= t;
		this->value[1] -= t;
		this->value[2] -= t;
		this->value[3] -= t;
		return *this;
	}

	template<typename T>
	inline
	const tmat4<T>& tmat4<T>::operator-=(const tmat4<T>& o) noexcept
	{
		this->value[0] -= o.value[0];
		this->value[1] -= o.value[1];
		this->value[2] -= o.value[2];
		this->value[3] -= o.value[3];
		return *this;
	}
	// ---------------------------------------------------------------------------
 	template<typename T>
	inline
	const tmat4<T>& tmat4<T>::operator*=(const T& t) noexcept
	{
		this->value[0] *= t;
		this->value[1] *= t;
		this->value[2] *= t;
		this->value[3] *= t;
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tmat4<T>& tmat4<T>::operator/=(const T& t) noexcept
	{
		this->value[0] /= t;
		this->value[1] /= t;
		this->value[2] /= t;
		this->value[3] /= t;
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	template<typename c>
	inline
	tmat4<T>::operator tmat4<c>() noexcept
	{
		return tmat4<c>((tvec4<c>)value[0], (tvec4<c>)value[1], (tvec4<c>)value[2], (tvec4<c>)value[3]);
	}

	template<typename T>
	inline
	tmat4<T>::operator tmat2<T>() noexcept
	{
		return tmat2<T>(tvec2<T>(value[0]), tvec2<T>(value[1]));
	}

	template<typename T>
	inline
	tmat4<T>::operator tmat3<T>() noexcept
	{
		return tmat3<T>(tvec3<T>(value[0]), tvec3<T>(value[1]), tvec3<T>(value[2]));
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat4<T> operator+ (const tmat4<T>& m, T t) noexcept
	{
		return tmat4<T>(m[0] + t, m[1] + t, m[2] + t, m[3] + t);
	}

	template<typename T>
	inline
	tmat4<T> operator+ (const T& t, tmat4<T> m) noexcept
	{
		return tmat4<T>(m[0] + t, m[1] + t, m[2] + t, m[3] + t);
	}

	template<typename T>
	inline
	tmat4<T> operator+ (const tmat4<T>& m, tmat4<T> o) noexcept
	{
		return tmat4<T>(m[0] + o[0], m[1] + o[1], m[2] + o[2], m[3] + o[3]);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat4<T> operator- (const tmat4<T>& m, T t) noexcept
	{
		return tmat4<T>(m[0] - t, m[1] - t, m[2] - t, m[3] - t);
	}

	template<typename T>
	inline
	tmat4<T> operator- (const T& t, tmat4<T> m) noexcept
	{
		return tmat4<T>(t - m[0], t - m[1], t - m[2], t - m[3]);
	}

	template<typename T>
	inline
	tmat4<T> operator- (const tmat4<T>& m, tmat4<T> o) noexcept
	{
		return tmat4<T>(m[0] - o[0], m[1] - o[1], m[2] - o[2], m[3] - o[3]);
	}

	template<typename T>
	inline
	tmat4<T> operator- (const tmat4<T>& m) noexcept
	{
		return tmat4<T>(-m[0], -m[1], -m[2], -m[3]);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat4<T> operator* (const tmat4<T>& m, T t) noexcept
	{
		return tmat4<T>(m[0] * t, m[1] * t, m[2] * t, m[3] * t);
	}

	template<typename T>
	inline
	tmat4<T> operator* (const T& t, tmat4<T> m) noexcept
	{
		return tmat4<T>(m[0] * t, m[1] * t, m[2] * t, m[3] * t);
	}

	template<typename T>
	inline
	tmat4<T> operator* (const tmat4<T>& o, tmat4<T> m) noexcept
	{
		return tmat4<T>(m[0][0] * o[0][0] + m[1][0] * o[0][1] + m[2][0] * o[0][2] + m[3][0] * o[0][3],
						m[0][1] * o[0][0] + m[1][1] * o[0][1] + m[2][1] * o[0][2] + m[3][1] * o[0][3],
						m[0][2] * o[0][0] + m[1][2] * o[0][1] + m[2][2] * o[0][2] + m[3][2] * o[0][3],
						m[0][3] * o[0][0] + m[1][3] * o[0][1] + m[2][3] * o[0][2] + m[3][3] * o[0][3],

						m[0][0] * o[1][0] + m[1][0] * o[1][1] + m[2][0] * o[1][2] + m[3][0] * o[1][3],
						m[0][1] * o[1][0] + m[1][1] * o[1][1] + m[2][1] * o[1][2] + m[3][1] * o[1][3],
						m[0][2] * o[1][0] + m[1][2] * o[1][1] + m[2][2] * o[1][2] + m[3][2] * o[1][3],
						m[0][3] * o[1][0] + m[1][3] * o[1][1] + m[2][3] * o[1][2] + m[3][3] * o[1][3],

						m[0][0] * o[2][0] + m[1][0] * o[2][1] + m[2][0] * o[2][2] + m[3][0] * o[2][3],
						m[0][1] * o[2][0] + m[1][1] * o[2][1] + m[2][1] * o[2][2] + m[3][1] * o[2][3],
						m[0][2] * o[2][0] + m[1][2] * o[2][1] + m[2][2] * o[2][2] + m[3][2] * o[2][3],
						m[0][3] * o[2][0] + m[1][3] * o[2][1] + m[2][3] * o[2][2] + m[3][3] * o[2][3],

						m[0][0] * o[3][0] + m[1][0] * o[3][1] + m[2][0] * o[3][2] + m[3][0] * o[3][3],
						m[0][1] * o[3][0] + m[1][1] * o[3][1] + m[2][1] * o[3][2] + m[3][1] * o[3][3],
						m[0][2] * o[3][0] + m[1][2] * o[3][1] + m[2][2] * o[3][2] + m[3][2] * o[3][3],
						m[0][3] * o[3][0] + m[1][3] * o[3][1] + m[2][3] * o[3][2] + m[3][3] * o[3][3]
			);
	}

	template<typename T>
	inline
	tvec4<T> operator* (const tmat4<T>& m, tvec4<T> v) noexcept
	{
		return tvec4<T>(v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3],
						v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + v.w * m[1][3],
						v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + v.w * m[2][3],
						v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + v.w * m[3][3]
						);
	}

	template<typename T>
	inline
	tvec4<T> operator* (const tvec4<T>& v, tmat4<T> m) noexcept
	{
		return tvec4<T>(v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + v.w * m[3][0],
						v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + v.w * m[3][1],
						v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + v.w * m[3][2],
						v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + v.w * m[3][3]
			);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat4<T> operator/ (const tmat4<T>& m, T t) noexcept
	{
		return tmat4<T>(m[0] / t, m[1] / t, m[2] / t, m[3] / t);
	}

	template<typename T>
	inline
	tmat4<T> operator/ (const T& t, tmat4<T> m) noexcept
	{
		return tmat4<T>(t / m[0], t / m[1], t / m[2], t / m[3]);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tmat4<T> transpose(const tmat4<T>& m) noexcept
	{
		return tmat4<T>(m[0][0], m[1][0], m[2][0], m[3][0],
						m[0][1], m[1][1], m[2][1], m[3][1],
						m[0][2], m[1][2], m[2][2], m[3][2],
						m[0][3], m[1][3], m[2][3], m[3][3]);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	tmat4<T> cofactor(const tmat4<T>& m) noexcept
	{
		return tmat4<T>((m[1][1] * m[2][2] - m[1][2] * m[2][1]), -(m[1][0] * m[2][2] - m[1][2] * m[2][0]), (m[1][0] * m[2][1] - m[1][1] * m[2][0]),

			-(m[0][1] * m[2][2] - m[0][2] * m[2][1]), (m[0][0] * m[2][2] - m[0][2] * m[2][0]), -(m[0][0] * m[2][1] - m[0][1] * m[2][0]),

			(m[0][1] * m[1][2] - m[0][2] * m[1][1]), -(m[0][0] * m[1][2] - m[0][2] * m[1][0]), (m[0][0] * m[1][1] - m[0][1] * m[1][0]));
	}
	// ---------------------------------------------------------------------------

	template<typename T>
	tmat4<T> adjoint(const tmat4<T>& m) noexcept
	{
		return tmat4<T>((m[1][1] * m[2][2] - m[1][2] * m[2][1]), -(m[0][1] * m[2][2] - m[0][2] * m[2][1]), (m[0][1] * m[1][2] - m[0][2] * m[1][1]),
			-(m[1][0] * m[2][2] - m[1][2] * m[2][0]), (m[0][0] * m[2][2] - m[0][2] * m[2][0]), -(m[0][0] * m[1][2] - m[0][2] * m[1][0]),
			(m[1][0] * m[2][1] - m[1][1] * m[2][0]), -(m[0][0] * m[2][1] - m[0][1] * m[2][0]), (m[0][0] * m[1][1] - m[0][1] * m[1][0]));
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
		T determinant(const tmat4<T>& m) noexcept
	{
		return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
			- m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
			+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
		tmat4<T> inverse(const tmat4<T>& m) noexcept
	{
		return ((T)1.0 / determinant(m)) * adjoint(m);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	T* value_ptr(tmat4<T>& m) noexcept
	{
		return &(m[0][0]);
	}
	// ---------------------------------------------------------------------------

}