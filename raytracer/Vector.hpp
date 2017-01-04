#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector{
private:
	double x, y, z;
public:
	Vector(void){}
	Vector(double x, double y, double z);
	void set(double x, double y, double z);
	double dot(Vector v);
	void normalize(void);

	Vector add(Vector v);
	Vector subtract(Vector v);
	Vector multiply(Vector v);

	Vector operator+(Vector v);
	Vector operator-(Vector v);
	Vector operator*(Vector v);

	Vector scalar_mult(double a);
	Vector operator*(double a);
	Vector scalar_divide(double a);
	Vector operator/(double a);

	double sum_components();
	double length();
};

#endif