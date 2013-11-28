/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef POINT3I_H
#define POINT3I_H

/* 3D Point with (signed) integers
 * Operator overloading! Cool!
 */

class Point3i
{
    public:
        int x, y, z;
        Point3i();
        Point3i(int x, int y, int z);
        Point3i operator+ (Point3i p);
        Point3i operator- (Point3i p);
        Point3i operator* (Point3i p);
        bool operator== (Point3i p);
        bool operator!= (Point3i p);
};

#endif // POINT3I_H
