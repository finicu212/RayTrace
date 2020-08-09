#include "Vec3.h"

template <typename T>
Vec3<T>::Vec3(T xCoord, T yCoord, T zCoord) : x(xCoord), y(yCoord), z(zCoord) {};

template <typename T>
T Vec3<T>::getX() const { return x };

template <typename T>
T Vec3<T>::getY() const { return y };

template <typename T>
T Vec3<T>::getZ() const { return z };
