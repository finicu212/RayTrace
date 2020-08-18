#pragma once
#include "Ray.h"

struct hitInfo
{
	bool hitEntity;
	Point3 location;
	Vec3 normal;
	// t_min < t < t_max
	double t;
};

// abstract class
class Entity
{
public:
	virtual hitInfo getHitInfo(const Ray& r, const hitInfo& info, double t_min, double t_max) const = 0;
};