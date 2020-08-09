#include "Vec3.h"

template <typename T>
Vec3<T>::Vec3(T xCoord, T yCoord, T zCoord) : x(xCoord), y(yCoord), z(zCoord) {};

template <typename T>
T Vec3<T>::getX() const { return x };

template <typename T>
T Vec3<T>::getY() const { return y };

template <typename T>
T Vec3<T>::getZ() const { return z };

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
