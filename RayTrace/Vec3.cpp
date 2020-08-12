#include "Vec3.h"
#include <iostream>

template <typename T>
Vec3<T>::Vec3(T xCoord, T yCoord, T zCoord) : x(xCoord), y(yCoord), z(zCoord) {};

/*** Getters ***/

template <typename T>
T Vec3<T>::getX() const { return x; };

template <typename T>
T Vec3<T>::getY() const { return y; };

template <typename T>
T Vec3<T>::getZ() const { return z; };

/*** Operator overloads ***/

template <typename T>
Vec3<T> Vec3<T>::operator + (const Vec3<T>& v) const
{
	return Vec3<T>(x + v.x, y + v.y, z + v.z);
}

template <typename T>
Vec3<T> Vec3<T>::operator - (const Vec3<T>& v) const
{
	return Vec3<T>(x - v.x, y - v.y, z - v.z);
}

template <typename T>
Vec3<T> Vec3<T>::operator * (double d) const
{
	return Vec3<T>(x * d, y * d, z * d);
}

template <typename T>
Vec3<T> Vec3<T>::operator / (double d) const
{
	return Vec3<T>(x / d, y / d, z / d);
}

template <typename T>
std::ostream& operator<< (std::ostream& o, const Vec3<T>& v)
{
	return o << v.x << ' ' << v.y << ' ' << v.z;
}

/*** Utility ***/

template <typename T>
T Vec3<T>::dot(const Vec3<T>& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

template <typename T>
Vec3<T> Vec3<T>::cross(const Vec3<T>& v) const
{
	return Vec3<T>(
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x);
}

template <typename T>
T Vec3<T>::norm() const
{
	return sqrt(x * x + y * y + z * z);
}

template <typename T>
Vec3<T> Vec3<T>::normalize()
{
	return this / this.norm();
}
