#include <iostream>
#include <vector>
#include "Sphere.h"
#include "Ray.h"
#include "Vec3.h"
#include "../includes/EasyBMP/EasyBMP.h"

Color rayColor(const Ray& r)
{
    Vec3 direction = r.getDirection().normalize();
    auto t = 0.5 * (direction.getY() + 1.0);

    // blendedValue = (1 - t) * startValue + t * endValue
    return Color(1.0, 1.0, 1.0) * (1 - t) + Color(0.5, 0.7, 1.0) * t;
}

bool render(const std::vector<Sphere>& spheres)
{
    const double ASPECT_RATIO = 16.0 / 9;
    const int IMAGE_WIDTH = 400;
    const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

    // Camera:
    const double VIEWPORT_HEIGHT = 2.0;
    const double VIEWPORT_WIDTH = ASPECT_RATIO * VIEWPORT_HEIGHT;
    const double FOCAL_LENGTH = 1.0;

    const Point3 ORIGIN = Point3(0, 0, 0);
    const Vec3 HORIZ_VEC = Vec3(VIEWPORT_WIDTH, 0, 0);
    const Vec3 VERTICAL_VEC = Vec3(0, VIEWPORT_HEIGHT, 0);
    const Point3 BOTTOM_LEFT = ORIGIN - HORIZ_VEC / 2 - VERTICAL_VEC / 2 - Vec3(0, 0, FOCAL_LENGTH);

    // BMP generation
    BMP image;
    image.SetSize(IMAGE_WIDTH, IMAGE_HEIGHT);
    image.SetBitDepth(24);

    // Render loop
    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            RGBApixel pixelCurrent = RGBApixel();

            double u = double(i) / IMAGE_WIDTH;
            double v = double(j) / IMAGE_HEIGHT;

            Ray r(ORIGIN, BOTTOM_LEFT + HORIZ_VEC * u + VERTICAL_VEC * v - ORIGIN);
            Color c = rayColor(r);

            pixelCurrent.Red = static_cast<int>(255 * c.getX());
            pixelCurrent.Green = static_cast<int>(255 * c.getY());
            pixelCurrent.Blue = static_cast<int>(255 * c.getZ());

            image.SetPixel(i, j, pixelCurrent);
        }
    }

    return image.WriteToFile("out.bmp");
}

int main()
{
    
}