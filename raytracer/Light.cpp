#include <math.h>
#include "Light.hpp"

Light::Light(double x, double y, double z){
	Vector loc(x, y, z);
	this->loc = loc;
}

COLOR_T Light::illuminate(RAY_T ray, COLOR_T obj_color, Vector int_pt, Vector normal){
	COLOR_T color;
	Vector L, R;
	double dot, dot2;

	//ambient
	color.r = 0.1 * obj_color.r;
	color.g = 0.1 * obj_color.g;
	color.b = 0.1 * obj_color.b;

	//diffuse
	L = loc - int_pt;
	L.normalize();
	dot = L.dot(normal);
	if(dot > 0){
		color.r += dot * obj_color.r;
		color.g += dot * obj_color.g;
		color.b += dot * obj_color.b;

		//specular
		Vector R = L - normal * (2.0 * dot);
		R.normalize();
		dot2 = R.dot(ray.dir);
		if(dot2 > 0){
			color.r += pow(dot2, 200);
            color.g += pow(dot2, 200);
            color.b += pow(dot2, 200);
		}
	}
	return color;
}