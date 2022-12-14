/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file vec4.inl
*/

#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

namespace oi
{
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T>& tvec4<T>::operator=(const tvec4& o) noexcept
	{
		this->x = o.x;
		this->y = o.y;
		this->z = o.z;
		this->w = o.w;
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator+=(const T& t) noexcept
	{
		this->x += t;
		this->y += t;
		this->z += t;
		this->w += t;
		return *this;
	}

	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator+=(const tvec4& o) noexcept
	{
		this->x += o.x;
		this->y += o.y;
		this->z += o.z;
		this->w += o.w;
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator-=(const T& t) noexcept
	{
		this->x -= t;
		this->y -= t;
		this->z -= t;
		this->w -= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator-=(const tvec4& o) noexcept
	{
		this->x -= o.x;
		this->y -= o.y;
		this->z -= o.z;
		this->w -= o.w;
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator*=(const T& t) noexcept
	{
		this->x *= t;
		this->y *= t;
		this->z *= t;
		this->w *= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator*=(const tvec4& o) noexcept
	{
		this->x *= o.x;
		this->y *= o.y;
		this->z *= o.z;
		this->w *= o.w;
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator/=(const T& t) noexcept
	{
		this->x /= t;
		this->y /= t;
		this->z /= t;
		this->w /= t;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
		T& tvec4<T>::operator[](const uint32_t& i) noexcept
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			break;
		}

		return x;
	}

	template<typename T>
	inline
		const T& tvec4<T>::operator[](const uint32_t& i) const noexcept
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			break;
		}

		return x;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	template<typename c>
	inline
	tvec4<T>::operator tvec4<c>() noexcept
	{
		return tvec4<c>(static_cast<c>(x), static_cast<c>(y), static_cast<c>(z), static_cast<c>(w));
	}

	template<typename T>
	template<typename c>
	inline
	tvec4<T>::operator tvec2<c>() noexcept
	{
		return tvec2<c>(static_cast<c>(x), static_cast<c>(y));
	}

	template<typename T>
	template<typename c>
	inline
	tvec4<T>::operator tvec3<c>() noexcept
	{
		return tvec3<c>(static_cast<c>(x), static_cast<c>(y), static_cast<c>(z));
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator+(const tvec4<T>& v, tvec4<T> u) noexcept
	{
		return tvec4<T>(v.x+u.x, v.y+u.y, v.z+u.z, v.w+u.w);
	}

	template<typename T>
	inline
	tvec4<T> operator+(const tvec4<T>& v, T t) noexcept
	{
		return tvec4<T>(v.x+t, v.y+t, v.z+t, v.w+t);
	}

	template<typename T>
	inline
	tvec4<T> operator+(const T& t, tvec4<T> v) noexcept
	{
		return tvec4<T>(v.x + t, v.y + t, v.z + t, v.w);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator-(const tvec4<T>& v, tvec4<T> u) noexcept
	{
		return tvec4<T>(v.x-u.x, v.y-u.y, v.z-u.z, v.w-u.w);
	}

	template<typename T>
	inline
	tvec4<T> operator-(const tvec4<T>& v, T t) noexcept
	{
		return tvec4<T>(v.x-t, v.y-t, v.z-t, v.w-t);
	}

	template<typename T>
	inline
	tvec4<T> operator-(const T& t, tvec4<T> v) noexcept
	{
		return tvec4<T>(t - v.x, t - v.y, t - v.z, t - v.w);
	}

	template<typename T>
	inline
	tvec4<T> operator-(const tvec4<T>& v) noexcept
	{
		return tvec4<T>(-v.x, -v.y, -v.z, -v.w);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator*(const tvec4<T>& v, tvec4<T> u) noexcept
	{
		return tvec4<T>(v.x*u.x, v.y*u.y, v.z*u.z, v.w*u.w);
	}

	template<typename T>
	inline
	tvec4<T> operator*(const tvec4<T>& v, T t) noexcept
	{
		return tvec4<T>(v.x*t, v.y*t, v.z*t, v.w*t);
	}

	template<typename T>
	inline
	tvec4<T> operator*(const T& t, tvec4<T> v) noexcept
	{
		return tvec4<T>(v.x*t, v.y*t, v.z*t, v.w*t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator/(const tvec4<T>& v, T t) noexcept
	{
		return tvec4<T>(v.x/t, v.y/t, v.z/t, v.w/t);
	}

	template<typename T>
	inline
	tvec4<T> operator/(const T& t, tvec4<T> v) noexcept
	{
		return tvec4<T>(t / v.x, t / v.y, t / v.z, t / v.w);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T length(const tvec4<T>& v) noexcept
	{
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> normalize(const tvec4<T>& o) noexcept
	{
		return o / length(o);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T* value_ptr(tvec4<T>& v) noexcept
	{
		return &(v.x);
	}
// ---------------------------------------------------------------------------
}