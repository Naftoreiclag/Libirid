#include "Point3i.h"

Point3i::Point3i()
: x(0), y(0), z(0)
{
}

Point3i::Point3i(int x, int y, int z)
: x(x), y(y), z(z)
{
}

// Adding
Point3i Point3i::operator+ (Point3i p)
{
    Point3i n;
    n.x = x + p.x;
    n.y = y + p.y;
    n.z = z + p.z;

    return n;
}

// Subtracting
Point3i Point3i::operator- (Point3i p)
{
    Point3i n;
    n.x = x - p.x;
    n.y = y - p.y;
    n.z = z - p.z;

    return n;
}

// Multiplication
Point3i Point3i::operator* (Point3i p)
{
    Point3i n;
    n.x = x * p.x;
    n.y = y * p.y;
    n.z = z * p.z;

    return n;
}

// Is equal
bool Point3i::operator== (Point3i p)
{
    return x == p.x && y == p.y && z == p.z;
}
