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
			hitInfo returnedInfo;
			returnedInfo.hitEntity = true;
			returnedInfo.location = r.pointAt(t0);
			returnedInfo.normal = (r.pointAt(t0) - center) / radius;
			returnedInfo.t = t0;
			return returnedInfo;
		}

		t0 = (-tcb + sqrt(delta)) / a;
		if (t0 > t_min && t0 < t_max)
		{
			hitInfo returnedInfo;
			returnedInfo.hitEntity = true;
			returnedInfo.location = r.pointAt(t0);
			returnedInfo.normal = (r.pointAt(t0) - center) / radius;
			returnedInfo.t = t0;
			return returnedInfo;
		}
	}

	hitInfo returnedInfo;
	returnedInfo.hitEntity = false;
	return returnedInfo;
}