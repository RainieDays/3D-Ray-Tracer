#ifndef LIGHT_HPP
#define LIGHT_HPP
#include "Vector.hpp"
#include "rt.hpp"

class Light{
private:
	Vector loc;
public:
	Light(double x, double y, double z);
	COLOR_T illuminate(RAY_T ray, COLOR_T obj_color, Vector int_pt, Vector normal);
};

#endif