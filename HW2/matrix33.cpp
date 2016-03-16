#include <iostream>
#include "matrix33.h"
using namespace std;
matrix33::matrix33(vector3 inv1, vector3 inv2, vector3 inv3){
	v1 = inv1;
	v2 = inv2;
	v3 = inv3;
}
matrix33::matrix33(const matrix33 &m){
	v1 = m.v1;
	v2 = m.v2;
	v3 = m.v3;
}
vector3 &matrix33::operator [] (unsigned int index){
	switch(index){
		case 0: return v1;
		case 1: return v2;
		case 2: return v3;
	}
}
const vector3 &matrix33::operator [] (unsigned int index) const{
	switch(index){
		case 0: return v1;
		case 1: return v2;
		case 2: return v3;
	}
}
matrix33 &matrix33::operator =  (const matrix33 &m){
	v1 = m.v1;
	v2 = m.v2;
	v3 = m.v3;
}
matrix33 &matrix33::operator += (const matrix33 &m){
	v1 += m.v1;
	v2 += m.v2;
	v3 += m.v3;
	return *this;
}
matrix33 &matrix33::operator -= (const matrix33 &m){
	v1 -= m.v1;
	v2 -= m.v2;
	v3 -= m.v3;
	return *this;
}
matrix33 &matrix33::operator *= (float f){
	v1 *= f;
	v2 *= f;
	v3 *= f;
	return *this;
}
matrix33 &matrix33::operator /= (float f){
	v1 /= f;
	v2 /= f;
	v3 /= f;
	return *this;
}
bool operator == (const matrix33 &a, const matrix33 &b){
	return (a.v1 == b.v1) && (a.v2 == b.v2) && (a.v3 == b.v3);
}
bool operator != (const matrix33 &a, const matrix33 &b){
	return !(a == b);
}
matrix33 operator - (const matrix33 &a){
	matrix33 m(-a.v1, -a.v2, -a.v3);
	return m;
}
matrix33 operator + (const matrix33 &a, const matrix33 &b){
	matrix33 m(a.v1 + b.v1, a.v2 + b.v2, a.v3 + b.v3);
	return m;
}
matrix33 operator - (const matrix33 &a, const matrix33 &b){
	matrix33 m(a.v1 - b.v1, a.v2 - b.v2, a.v3 - b.v3);
	return m;
}
matrix33 operator * (const matrix33 &a, float f){
	matrix33 m(a.v1 * f, a.v2 * f, a.v3 * f);
	return m;
}
matrix33 operator * (float f, const matrix33 &a){
	matrix33 m(a.v1 * f, a.v2 * f, a.v3 * f);
	return m;
}
matrix33 operator / (const matrix33 &a, float f){
	matrix33 m(a.v1 / f, a.v2 / f, a.v3 / f);
	return m;
}
void matrix33::printMatrix(){
	v1.printVector3();
	v2.printVector3();
	v3.printVector3();
}
matrix33 &matrix33::invert(){
	matrix33 m = *this;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			(*this)[i][j] = m[j][i];
	return *this;
}
matrix33 &matrix33::identity(){
	v1.set(1, 0, 0);
	v2.set(0, 1, 0);
	v3.set(0, 0, 1);
	return *this;
}
int matrix33::determinant(){
	int det = 0;
	det += v1[0] * v2[1] * v3[2];
	det += v1[2] * v2[0] * v3[1];
	det += v1[1] * v2[2] * v3[0];
	det -= v1[2] * v2[1] * v3[0];
	det -= v1[0] * v2[2] * v3[1];
	det -= v1[1] * v2[0] * v3[2];
	return det;
}
