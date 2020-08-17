#pragma once
#include "Ray.h"

struct hitInfo
{
	Point3 location;
	Vec3 normal;
	// t_min < t < t_max
	double t;

	void update(Point3 loc, Vec3 n, double t)
	{
		this->location = loc;
		this->normal = n;
		this->t = t;
	}
};

// abstract class
class Entity
{
public:
	virtual bool isHit(const Ray& r, hitInfo& info, double t_min, double t_max) const = 0;
};