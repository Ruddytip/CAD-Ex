#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

#if defined(_MSC_VER)
//  Microsoft
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import / export semantics.
#endif

template <typename TYPE>
struct EXPORT Point3D final
{
    TYPE x;
    TYPE y;
    TYPE z;
    Point3D(const TYPE &_x, const TYPE &_y, const TYPE &_z) : x(_x), y(_y), z(_z) {};
};

template <typename TYPE>
struct EXPORT Vector3D final
{
    TYPE x;
    TYPE y;
    TYPE z;
    Vector3D(const TYPE &_x, const TYPE &_y, const TYPE &_z) : x(_x), y(_y), z(_z) {};
};
