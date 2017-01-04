#include "Sphere.hpp"
#include <math.h>


void Sphere::set(Vector ctr, double rad){
	this->ctr = ctr;
	this->rad = rad;
}

bool Sphere::intersect(RAY_T ray, double &t, Vector &int_pt, Vector &normal){
	double a, b, c, discriminant;
	float t0, t1;
	a = 1.0;
	b = 2.0 * ray.dir.dot(ray.orig - ctr);
	c = ((ray.orig - ctr) * (ray.orig - ctr)).sum_components() - rad * rad;

    discriminant = b*b - 4*a*c;
    if(discriminant < 0){
		return false;
	}
    t0 = (-b + sqrt(discriminant)) / (2*a);
	t1 = (-b - sqrt(discriminant)) / (2*a);
	
    if(t1 < 0 && t0 < 0){
		return false;
	}
    t = (t0 < t1) ? t0 : t1;

    int_pt = ray.orig + ray.dir * t;
    normal = (int_pt - ctr) / rad;

    return true;
}