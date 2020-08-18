#pragma once
#include "Ray.h"

struct hitInfo
{
	bool hitEntity;
	Point3 location;
	Vec3 normal;
	// t_min < t < t_max
	double t;

	void update(bool hitSomething, Point3 loc, Vec3 n, double t)
	{
		this->hitEntity = hitSomething;
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