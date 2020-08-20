#pragma once
#include "Ray.h"

class Camera
{
public:
    Camera()
    {
        const double ASPECT_RATIO = 16.0 / 9;
        const double VIEWPORT_HEIGHT = 2.0;
        const double VIEWPORT_WIDTH = ASPECT_RATIO * VIEWPORT_HEIGHT;
        const double FOCAL_LENGTH = 1.0;

        const Point3 ORIGIN = Point3(0, 0, 0);
        const Vec3 HORIZ_VEC = Vec3(VIEWPORT_WIDTH, 0, 0);
        const Vec3 VERTICAL_VEC = Vec3(0, VIEWPORT_HEIGHT, 0);
        const Point3 BOTTOM_LEFT = ORIGIN - HORIZ_VEC / 2 - VERTICAL_VEC / 2 - Vec3(0, 0, FOCAL_LENGTH);
    }

    Ray get_ray(double u, double v) const
    {
        return Ray(ORIGIN, BOTTOM_LEFT + u * HORIZ_VEC + v * VERTICAL_VEC - ORIGIN);
    }

private:
    Point3 ORIGIN;
    Point3 BOTTOM_LEFT;
    Vec3 HORIZ_VEC;
    Vec3 VERTICAL_VEC;
};