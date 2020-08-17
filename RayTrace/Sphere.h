#pragma once
#include "Entity.h"

class Sphere : Entity
{
public:
	Sphere(Point3 c, double r) :
		center(c), radius(r)
	{};

	virtual bool isHit(const Ray& r, const hitInfo& info, double t_min, double t_max) const override;

private:
	Point3 center;
	double radius;
};

bool Sphere::isHit(const Ray& r, const hitInfo& info, double t_min, double t_max) const
{
	Vec3 Len = center - r.getOrigin();

	return false;
}