#include <iostream>
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

int main()
{

    // Image
    const double ASPECT_RATIO = 16.0 / 9;
    const int IMAGE_WIDTH = 400;
    const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

    BMP image;
    image.SetSize(IMAGE_WIDTH, IMAGE_HEIGHT);
    image.SetBitDepth(24);

    // Camera

    double VIEWPORT_HEIGHT = 2.0;
    double VIEWPORT_WIDTH = ASPECT_RATIO * VIEWPORT_HEIGHT;
    double FOCAL_LENGTH = 1.0;

    auto origin = Point3(0, 0, 0);
    auto horizontal = Vec3(VIEWPORT_WIDTH, 0, 0);
    auto vertical = Vec3(0, VIEWPORT_HEIGHT, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, FOCAL_LENGTH);

    // Render
    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            RGBApixel pixelCurrent = RGBApixel();

            double u = double(i) / IMAGE_WIDTH;
            double v = double(j) / IMAGE_HEIGHT;

            Ray r(origin, lower_left_corner + horizontal * u + vertical * v - origin);
            Color c = rayColor(r);

            pixelCurrent.Red = static_cast<int>(255 * c.getX());
            pixelCurrent.Green = static_cast<int>(255 * c.getY());
            pixelCurrent.Blue = static_cast<int>(255 * c.getZ());

            image.SetPixel(i, j, pixelCurrent);
        }
    }

    image.WriteToFile("out.bmp");
}