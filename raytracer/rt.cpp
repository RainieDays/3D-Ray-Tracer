#include <iostream>
#include <stdlib.h>
#include "rt.hpp"
#include "Light.hpp"
#include "obj.hpp"

void read_objs(OBJ_T **list){
	double cx, cy, cz, rad, r, g, b;
	Vector vec;
	OBJ_T *node;
	*list = NULL;
	while (std::cin >> cx >> cy >> cz >> rad >> r >> g >> b) {
        node = (OBJ_T *)malloc(sizeof(OBJ_T));
        Vector vec(cx, cy, cz);
        node->sphere.set(vec, rad);
        node->color.r = r;
        node->color.g = g;
        node->color.b = b;
        node->next = *list;
        *list = node;
    }
}

COLOR_T trace(RAY_T ray, OBJ_T *list, Light light) {
	double t;
	double min_t = 1000.0;
	COLOR_T color;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	Vector int_pt, closest_int_pt, normal, closest_normal;
	OBJ_T *obj, *closest_obj = NULL;

	for(obj = list; obj != NULL; obj = obj->next){
		//finds closest intersection, returns color of closest sphere
		if(obj->sphere.intersect(ray, t, int_pt, normal)){
			if(t < min_t){
				min_t = t;
				closest_obj = obj;
				closest_int_pt = int_pt;
				closest_normal = normal;
			}
		}
	}
	if(closest_obj != NULL){
		color = light.illuminate(ray, closest_obj->color, closest_int_pt, closest_normal);
	}
	return color;
}

int main(){
	//define variables
	RAY_T ray;
	COLOR_T color;
	int x, y;
	OBJ_T *current;
	OBJ_T *list = NULL;

	//reads spheres from stdin, creates linked list
	read_objs(&list);

	//header for image
	std::cout << "P6\n1000 1000\n255\n";

	//iterate through pixels
	for(y = 0; y < 1000; y++){
		for(x= 0; x < 1000; x++){
			ray.orig.set(0.0, 0.0, 0.0);
			ray.dir.set(-0.5 + x/1000.0, 0.5 - y/1000.0, 1.0);
			Light light(5.0,10.0,0.0);

			//normalize the direction 
			ray.dir. normalize();
			//returns color of closest sphere
			color = trace(ray, list, light);
			std::cout
				<< (unsigned char)((color.r < 1 ? color.r : 1) * 255)
                << (unsigned char)((color.g < 1 ? color.g : 1) * 255)
                << (unsigned char)((color.b < 1 ? color.b : 1) * 255);
		}
	}
	//frees the memory
	while(list != NULL){
		current = list;
		list = list->next;
		free(current);
	}
}