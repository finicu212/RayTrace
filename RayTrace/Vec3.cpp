#include "Vec3.h"
#include <iostream>

Vec3::Vec3(double xCoord, double yCoord, double zCoord) 
	: x(xCoord), y(yCoord), z(zCoord) 
{};

/*** Getters ***/

double Vec3::getX() const { return x; };

double Vec3::getY() const { return y; };

double Vec3::getZ() const { return z; };

/*** Operator overloads ***/

Vec3 Vec3::operator + (const Vec3& v) const
{
	return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator - (const Vec3& v) const
{
	return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator * (double d) const
{
	return Vec3(x * d, y * d, z * d);
}

Vec3 Vec3::operator / (double d) const
{
	return Vec3(x / d, y / d, z / d);
}

std::ostream& operator<< (std::ostream& o, const Vec3& v)
{
	return o << v.getX() << ' ' << v.getY() << ' ' << v.getZ();
}

/*** Utility ***/

double Vec3::dot(const Vec3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::cross(const Vec3& v) const
{
	return Vec3(
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x);
}

double Vec3::norm() const
{
	return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize()
{
	return *this / this->norm();
}