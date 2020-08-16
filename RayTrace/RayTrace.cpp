#include <iostream>
#include "../includes/EasyBMP/EasyBMP.h"

int main() {

    // Image

    const int IMAGE_WIDTH = 256;
    const int IMAGE_HEIGHT = 256;

    // Render

    BMP image;
    image.SetSize(IMAGE_WIDTH, IMAGE_HEIGHT);
    image.SetBitDepth(16);

    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            RGBApixel pixelCurrent = RGBApixel();

            pixelCurrent.Alpha = 255;

            auto r = double(i) / (IMAGE_WIDTH - 1);
            auto g = double(j) / (IMAGE_HEIGHT - 1);
            auto b = 0.25;

            pixelCurrent.Red = static_cast<int>(255 * r);
            pixelCurrent.Green = static_cast<int>(255 * g);
            pixelCurrent.Blue = static_cast<int>(255 * b);

            image.SetPixel(j, i, pixelCurrent);
        }
    }

    image.WriteToFile("out.bmp");
}