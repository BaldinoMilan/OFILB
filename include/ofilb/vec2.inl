/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file vec2.inl
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
	tvec2<T>& tvec2<T>::operator=(const tvec2& o)
	{
		this->x = o.x; 
		this->y = o.y;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec2<T>& tvec2<T>::operator+=(const T& t)
	{
		this->x += t; 
		this->y += t;
		return *this;
	}

	template<typename T>
	inline 
	const tvec2<T>& tvec2<T>::operator+=(const tvec2& o)
	{
		this->x += o.x; 
		this->y += o.y;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec2<T>& tvec2<T>::operator-=(const T& t)
	{
		this->x -= t;
		this->y -= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec2<T>& tvec2<T>::operator-=(const tvec2& o)
	{
		this->x -= o.x; 
		this->y -= o.y;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec2<T>& tvec2<T>::operator*=(const T& t)
	{
		this->x *= t; 
		this->y *= t;
		return *this;
	}

	template<typename T>
	inline
	const tvec2<T>& tvec2<T>::operator*=(const tvec2& o)
	{
		this->x *= o.x; 
		this->y *= o.y;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	const tvec2<T>& tvec2<T>::operator/=(const T& t)
	{
		this->x /= t; 
		this->y /= t;
		return *this;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline 
	T& tvec2<T>::operator[](const uint32_t& i)
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			break;
		}

		return x;
	}

	template<typename T>
	inline
	const T& tvec2<T>::operator[](const uint32_t& i) const
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			break;
		}

		return x;
	}
// ---------------------------------------------------------------------------
	template<typename T>
	template<typename C>
	inline 
	tvec2<T>::operator tvec2<C>()
	{
		return tvec2<C>(static_cast<C>(x), static_cast<C>(y));
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec2<T> operator+(const tvec2<T>& v, tvec2<T> u)
	{
		return tvec2<T>(v.x + u.x, v.y + u.y);
	}

	template<typename T>
	inline
	tvec2<T> operator+(const tvec2<T>& v, T t)
	{
		return tvec2<T>(v.x + t, v.y + t);
	}

	template<typename T>
	inline
	tvec2<T> operator+(const T& t, tvec2<T> v)
	{
		return tvec2<T>(v.x + t, v.y + t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec2<T> operator-(const tvec2<T>& v, tvec2<T> u)
	{
		return tvec2<T>(v.x - u.x, v.y - u.y);
	}

	template<typename T>
	inline
	tvec2<T> operator-(const tvec2<T>& v, T t)
	{
		return tvec2<T>(v.x - t, v.y - t);
	}
	
	template<typename T>
	inline
	tvec2<T> operator-(const T& t, tvec2<T> v)
	{
		return tvec2<T>(t-v.x, t-v.y);
	}

	template<typename T>
	inline
	tvec2<T>  operator-(const tvec2<T>& v)
	{
		return tvec2<T>(-v.x, -v.y);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec2<T> operator*(const tvec2<T>& v, tvec2<T> u)
	{
		return tvec2<T>(v.x * u.x, v.y * u.y);
	}

	template<typename T>
	inline
	tvec2<T> operator*(const tvec2<T>& v, T t)
	{
		return tvec2<T>(v.x * t, v.y * t);
	}

	template<typename T>
	inline
	tvec2<T> operator*(const T& t, tvec2<T> v)
	{
		return tvec2<T>(v.x*t, v.y*t);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec2<T> operator/(const tvec2<T>& v, T t)
	{
		return tvec2<T>(v.x / t, v.y / t);
	}

	template<typename T>
	inline
	tvec2<T> operator/(const T& t, tvec2<T> v)
	{
		return tvec2<T>(t/v.x, t/v.y);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T length(const tvec2<T>& v)
	{
		return sqrt(v.x*v.x + v.y*v.y);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	tvec2<T> normalize(const tvec2<T>& o)
	{
		return o / length(o);
	}
// ---------------------------------------------------------------------------
	template<typename T>
	inline
	T* value_ptr(tvec2<T>& v)
	{
		return &(v.x);
	}
// ---------------------------------------------------------------------------

}