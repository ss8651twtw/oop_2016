#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33
{  
public:
	vector3 v1, v2, v3;

public:
	matrix33() {};
	matrix33(vector3 inv1, vector3 inv2, vector3 inv3);
	matrix33(const matrix33 &a);

public:
	vector3 &operator [] (unsigned int index);
	const vector3 &operator [] (unsigned int index) const;
	matrix33 &operator =  (const matrix33 &a);
	matrix33 &operator += (const matrix33 &a);
	matrix33 &operator -= (const matrix33 &a);
	matrix33 &operator *= (float f);
	matrix33 &operator /= (float f);
	friend bool operator == (const matrix33 &a, const matrix33 &b);
	friend bool operator != (const matrix33 &a, const matrix33 &b);
	friend matrix33 operator - (const matrix33 &a);
	friend matrix33 operator + (const matrix33 &a, const matrix33 &b);
	friend matrix33 operator - (const matrix33 &a, const matrix33 &b);
	friend matrix33 operator * (const matrix33 &a, float f);
	friend matrix33 operator * (float f, const matrix33 &a);
	friend matrix33 operator * (const matrix33 &a, const matrix33 &b);
	friend matrix33 operator / (const matrix33 &a, float f);

public:
	void printMatrix();
	matrix33 &invert();
	matrix33 &identity();
	int determinant();
};

#endif
