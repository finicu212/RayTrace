#pragma once
#include "Ray.h"

class Camera
{
public:
    Camera()
    {
        ASPECT_RATIO = 16.0 / 9;
        VIEWPORT_HEIGHT = 2.0;
        VIEWPORT_WIDTH = ASPECT_RATIO * VIEWPORT_HEIGHT;
        FOCAL_LENGTH = 1.0;

        ORIGIN = Point3(0, 0, 0);
        HORIZ_VEC = Vec3(VIEWPORT_WIDTH, 0, 0);
        VERTICAL_VEC = Vec3(0, VIEWPORT_HEIGHT, 0);
        BOTTOM_LEFT = ORIGIN - HORIZ_VEC / 2 - VERTICAL_VEC / 2 - Vec3(0, 0, FOCAL_LENGTH);
    }

    Ray getRay(double u, double v) const
    {
        return Ray(ORIGIN, BOTTOM_LEFT + HORIZ_VEC * u + VERTICAL_VEC * v - ORIGIN);
    }

private:
    double ASPECT_RATIO;
    double VIEWPORT_HEIGHT;
    double VIEWPORT_WIDTH;
    double FOCAL_LENGTH;

    Point3 ORIGIN;
    Point3 BOTTOM_LEFT;
    Vec3 HORIZ_VEC;
    Vec3 VERTICAL_VEC;
};