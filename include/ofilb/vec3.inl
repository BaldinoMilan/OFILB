/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file vec3.inl
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
	tvec3<T>& tvec3<T>::operator=(const tvec3& o)
	{
		this->x = o.x;
		this->y = o.y;
		this->z = o.z;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator+=(const T& t)
	{
		this->x += t;
		this->y += t;
		this->z += t;
		return *this;
	}

	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator+=(const tvec3& o)
	{
		this->x += o.x;
		this->y += o.y;
		this->z += o.z;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator-=(const T& t)
	{
		this->x -= t;
		this->y -= t;
		this->z -= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator-=(const tvec3& o)
	{
		this->x -= o.x;
		this->y -= o.y;
		this->z -= o.z;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator*=(const T& t)
	{
		this->x *= t;
		this->y *= t;
		this->z *= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator*=(const tvec3& o)
	{
		this->x *= o.x;
		this->y *= o.y;
		this->z *= o.z;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator/=(const T& t)
	{
		this->x /= t;
		this->y /= t;
		this->z /= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec3<T>& tvec3<T>::operator/=(const tvec3& o)
	{
		this->x /= o.x;
		this->y /= o.y;
		this->z /= o.z;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T& tvec3<T>::operator[](const uint32_t& i)
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
		}

		return x;
	}

	template<typename T>
	inline
	const T& tvec3<T>::operator[](const uint32_t& i) const
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
		}

		return x;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	template<typename C>
	inline
	tvec3<T>::operator tvec3<C>()
	{
		return tvec3<C>(static_cast<C>(x), static_cast<C>(y), static_cast<C>(z));
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec3<T> operator+(const tvec3<T>& v, tvec3<T> u)
	{
		return tvec3<T>(v.x+u.x, v.y+u.y, v.z+u.z);
	}

	template<typename T>
	inline
	tvec3<T> operator+(const tvec3<T>& v, T t)
	{
		return tvec3<T>(v.x+t, v.y+t, v.z+t);
	}

	template<typename T>
	inline
	tvec3<T> operator+(const T& t, tvec3<T> v)
	{
		return tvec3<T>(v.x + t, v.y + t, v.z + t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec3<T> operator-(const tvec3<T>& v, tvec3<T> u)
	{
		return tvec3<T>(v.x-u.x, v.y-u.y, v.z-u.z);
	}

	template<typename T>
	inline
	tvec3<T> operator-(const tvec3<T>& v, T t)
	{
		return tvec3<T>(v.x-t, v.y-t, v.z-t);
	}

	template<typename T>
	inline
	tvec3<T> operator-(const T& t, tvec3<T> v)
	{
		return tvec3<T>(t-v.x, t-v.y, t - v.z);
	}

	template<typename T>
	inline
	tvec3<T>  operator-(const tvec3<T>& v)
	{
		return tvec3<T>(-v.x, -v.y, -v.z);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec3<T> operator*(const tvec3<T>& v, tvec3<T> u)
	{
		return tvec3<T>(v.x*u.x, v.y*u.y, v.z*u.z);
	}

	template<typename T>
	inline
	tvec3<T> operator*(const tvec3<T>& v, T t)
	{
		return tvec3<T>(v.x*t, v.y*t, v.z*t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec3<T> operator/(const tvec3<T>& v, tvec3<T> u)
	{
		return tvec3<T>(v.x/u.x, v.y/u.y, v.z/u.z);
	}

	template<typename T>
	inline
	tvec3<T> operator/(const tvec3<T>& v, T t)
	{
		return tvec3<T>(v.x/t, v.y/t, v.z/t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T length(const tvec3<T>& v)
	{
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec3<T> normalize(const tvec3<T>& o)
	{
		return o / length(o);
	}

}