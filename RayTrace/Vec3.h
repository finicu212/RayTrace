#pragma once

template <typename T>
class Vec3
{
private:
	T x, y, z;

public:
	Vec3(T xCoord, T yCoord, T zCoord);

	T getX() const;
	T getY() const;
	T getZ() const;

	Vec3<T> operator + (const Vec3<T>& v) const;
	Vec3<T> operator - (const Vec3<T>& v) const;
	Vec3<T> operator * (double d) const;
	Vec3<T> operator / (double d) const;
};