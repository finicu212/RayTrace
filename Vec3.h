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
};