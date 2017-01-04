#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "Vector.hpp"
#include "rt.hpp"

class Sphere{
private:
	Vector ctr;
	double rad;
public:
	Sphere(void){}
	void set(Vector ctr, double rad);
	bool intersect(RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};

#endif