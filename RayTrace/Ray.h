#pragma once
#include "Vec3.cpp"

class Ray 
{
private:
    Point3 orig;
    Vec3 dir;

public:
    Ray(const Point3& origin, const Vec3& direction)
        : orig(origin), dir(direction)
    {}

    Point3 getOrigin() const { return orig; }
    Vec3 getDirection() const { return dir; }

    /// <summary>
    /// Gets 3D point along this line, at parameter t.
    /// </summary>
    /// <param name="t">Distance from origin</param>
    /// <returns>3D point</returns>
    Point3 pointAt(double t) const 
    {
        return orig + dir * t;
    }
};