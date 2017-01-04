#include "Vector.hpp"
#include <math.h>

void Vector::set(double x,double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(double x, double y, double z){
	set(x, y, z);
}

Vector Vector::add(Vector v){
	Vector ret;
	ret.x = x + v.x;
	ret.y = y + v.y;
	ret.z = z + v.z;
	return ret;
}

Vector Vector::operator+(Vector v){
	return this->add(v);
}

Vector Vector::subtract(Vector v){
	Vector ret;
	ret.x = x - v.x;
	ret.y = y - v.y;
	ret.z = z - v.z;
	return ret;
}

Vector Vector::operator-(Vector v){
	return this->subtract(v);
}

Vector Vector::multiply(Vector v){
	Vector ret;
	ret.x = x * v.x;
	ret.y = y * v.y;
	ret.z = z * v.z;
	return ret;
}

Vector Vector::operator*(Vector v){
	return this->multiply(v);
}

Vector Vector::scalar_mult(double a){
	Vector ret;
	ret.x = x * a;
	ret.y = y * a;
	ret.z = z * a;
	return ret;
}

Vector Vector::operator*(double a){
	return this->scalar_mult(a);
}

Vector Vector::scalar_divide(double a){
	Vector ret;
	ret.x = x / a;
	ret.y = y / a;
	ret.z = z / a;
	return ret;
}

Vector Vector::operator/(double a){
	return this->scalar_divide(a);
}

double Vector::sum_components(){
	return x + y + z;
}

double Vector::length(){
	return sqrt(x*x + y*y + z*z);
}

double Vector::dot(Vector v){
	return (x*v.x + y*v.y + z*v.z);
}

void Vector::normalize(){
	double len = length();
	x /= len;
	y /= len;
	z /= len;
}

