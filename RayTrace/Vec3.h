#include <iostream>
#pragma once

class Vec3
{
private:
	double x, y, z;

public:
	Vec3();
	Vec3(double xCoord, double yCoord, double zCoord);

	double getX() const;
	double getY() const;
	double getZ() const;

	Vec3 operator + (const Vec3& v) const;
	Vec3 operator - (const Vec3& v) const;
	Vec3 operator * (double d) const;
	Vec3 operator / (double d) const;

	/// <summary>
	/// Returns the dot product of the two vectors
	/// </summary>
	/// <param name="v">Second vector</param>
	/// <returns>Scalar containing dot product</returns>
	double dot(const Vec3& v) const;

	/// <summary>
	/// Returns the cross product of the two vectors
	/// </summary>
	/// <param name="v">Second vector</param>
	/// <returns>Vec3 normal to the plane formed by the two given vecs</returns>
	Vec3 cross(const Vec3& v) const;

	/// <returns> norm (magnitude) of this vector </returns>
	double norm() const;

	/// <summary>
	/// Normalizes this vector (makes the norm 1)
	/// </summary>
	/// <returns>A Vec3 object which is now normalized</returns>
	Vec3 normalize();
};