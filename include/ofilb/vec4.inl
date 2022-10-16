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
	tvec4<T>& tvec4<T>::operator=(const tvec4& o)
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
	const tvec4<T>& tvec4<T>::operator+=(const T& t)
	{
		this->x += t;
		this->y += t;
		this->z += t;
		this->w += t;
		return *this;
	}

	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator+=(const tvec4& o)
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
	const tvec4<T>& tvec4<T>::operator-=(const T& t)
	{
		this->x -= t;
		this->y -= t;
		this->z -= t;
		this->w -= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator-=(const tvec4& o)
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
	const tvec4<T>& tvec4<T>::operator*=(const T& t)
	{
		this->x *= t;
		this->y *= t;
		this->z *= t;
		this->w *= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator*=(const tvec4& o)
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
	const tvec4<T>& tvec4<T>::operator/=(const T& t)
	{
		this->x /= t;
		this->y /= t;
		this->z /= t;
		this->w /= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec4<T>& tvec4<T>::operator/=(const tvec4& o)
	{
		this->x /= o.x;
		this->y /= o.y;
		this->z /= o.z;
		this->w /= o.w;
		return *this;
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
		T& tvec4<T>::operator[](const uint32_t& i)
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
		const T& tvec4<T>::operator[](const uint32_t& i) const
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
	template<typename C>
	inline
	tvec4<T>::operator tvec4<C>()
	{
		return tvec4<C>(static_cast<C>(x), static_cast<C>(y), static_cast<C>(z), static_cast<C>(w));
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator+(const tvec4<T>& v, tvec4<T> u)
	{
		return tvec4<T>(v.x+u.x, v.y+u.y, v.z+u.z, v.w+u.w);
	}

	template<typename T>
	inline
	tvec4<T> operator+(const tvec4<T>& v, T t)
	{
		return tvec4<T>(v.x+t, v.y+t, v.z+t, v.w+t);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator-(const tvec4<T>& v, tvec4<T> u)
	{
		return tvec4<T>(v.x-u.x, v.y-u.y, v.z-u.z, v.w-u.w);
	}

	template<typename T>
	inline
	tvec4<T> operator-(const tvec4<T>& v, T t)
	{
		return tvec4<T>(v.x-t, v.y-t, v.z-t, v.w-t);
	}

	template<typename T>
	inline
	tvec4<T> operator-(const T& t, tvec4<T> v)
	{
		return tvec4<T>(t - v.x, t - v.y, t - v.z, t - v.w);
	}

	template<typename T>
	inline
	tvec4<T> operator-(const tvec4<T>& v)
	{
		return tvec4<T>(-v.x, -v.y, -v.z, -v.w);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator*(const tvec4<T>& v, tvec4<T> u)
	{
		return tvec4<T>(v.x*u.x, v.y*u.y, v.z*u.z, v.w*u.w);
	}

	template<typename T>
	inline
	tvec4<T> operator*(const tvec4<T>& v, T t)
	{
		return tvec4<T>(v.x*t, v.y*t, v.z*t, v.w*t);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> operator/(const tvec4<T>& v, tvec4<T> u)
	{
		return tvec4<T>(v.x/u.x, v.y/u.y, v.z/u.z, v.w/u.w);
	}

	template<typename T>
	inline
	tvec4<T> operator/(const tvec4<T>& v, T t)
	{
		return tvec4<T>(v.x/t, v.y/t, v.z/t, v.w/t);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T length(const tvec4<T>& v)
	{
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
	}
	// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec4<T> normalize(const tvec4<T>& o)
	{
		return o / length(o);
	}

}