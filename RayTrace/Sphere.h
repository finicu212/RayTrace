#pragma once
#include "Entity.h"

class Sphere : Entity
{
public:
	Sphere(Point3 c, double r) :
		center(c), radius(r)
	{};

	hitInfo isHit(const Ray& r, const hitInfo& info, double t_min, double t_max) const;

private:
	Point3 center;
	double radius;
};

hitInfo Sphere::isHit(const Ray& r, const hitInfo& info, double t_min, double t_max) const
{
	hitInfo returnedInfo();

	Vec3 Len = center - r.getOrigin();
	double a = r.getDirection().norm() * r.getDirection().norm();
	double tcb = Len.dot(r.getDirection());
	double c = Len.norm() * Len.norm() - radius * radius;
	
	double delta = tcb * tcb - a * c;

	if (delta > 0)
	{
		double t0;
		t0 = (-tcb - sqrt(delta)) / a;
		if (t0 > t_min && t0 < t_max)
		{
			info.hitEntity = true;
			info.location = r.pointAt(t0);
			info.normal = (r.pointAt(t0) - center) / radius;
			info.t = t0;
			return info;
		}

		t0 = (-tcb + sqrt(delta)) / a;
		if (t0 > t_min && t0 < t_max)
		{
			info.hitEntity = true;
			info.location = r.pointAt(t0);
			info.normal = (r.pointAt(t0) - center) / radius;
			info.t = t0;
			return info;
		}
	}

	return false;
}