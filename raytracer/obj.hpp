#ifndef OBJ_HPP
#define OBJ_HPP
#include "Sphere.hpp"
#include "rt.hpp"

typedef struct Object{
	Sphere sphere;
	COLOR_T color;
	struct Object *next;
} OBJ_T;

#endif