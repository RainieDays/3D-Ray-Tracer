#ifndef RT_HPP
#define RT_HPP
#include "Vector.hpp"

typedef struct{
	Vector orig;
	Vector dir;
} RAY_T;

typedef struct{
	double r, g, b;
} COLOR_T;

#endif