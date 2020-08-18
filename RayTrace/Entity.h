#pragma once
#include "Ray.h"

struct hitInfo
{
	bool hitEntity, hitFrontFace;
	Point3 location;
	Vec3 normal;
	// t_min < t < t_max
	double t;

	void updateHitFrontFace(const Ray& r, const Vec3& outNormal)
	{
		if (r.getDirection().dot(outNormal) < 0)
		{
			hitFrontFace = true;
			// update our normal too such that it's the correct way up
			normal = outNormal;
		}
		else
		{
			hitFrontFace = false;
			normal = -outNormal;
		}
	}
};

// abstract class
class Entity
{
public:
	virtual hitInfo getHitInfo(const Ray& r, const hitInfo& info, double t_min, double t_max) const = 0;
};