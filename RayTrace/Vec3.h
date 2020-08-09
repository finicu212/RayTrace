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

	/// <summary>
	/// Returns the dot product of the two vectors
	/// </summary>
	/// <param name="v">Second vector</param>
	/// <returns>Scalar containing dot product</returns>
	T dot(const Vec3<T>& v) const;

	/// <summary>
	/// Returns the cross product of the two vectors
	/// </summary>
	/// <param name="v">Second vector</param>
	/// <returns>Vec3 normal to the plane formed by the two given vecs</returns>
	Vec3<T> cross(const Vec3<T>& v) const;

	/// <returns> norm (magnitude) of this vector </returns>
	T norm() const;

	/// <summary>
	/// Normalizes this vector
	/// </summary>
	/// <returns>A reference to this vector which is now normalized</returns>
	Vec3<T>& normalize();
};