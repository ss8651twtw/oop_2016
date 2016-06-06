#include <cstdio>
#include <cmath>
#include <algorithm>
#include "0416077_vector2.h"
using namespace std;
vector2::vector2(float inX, float inY){
	x = inX;
	y = inY;
}
vector2::vector2(const vector2 &v){
	x = v.x;
	y = v.y;
}
float &vector2::operator [] (unsigned int index){
	switch(index){
		case 0: return x;
		case 1: return y;
	}
}
const float &vector2::operator [] (unsigned int index) const{
	switch(index){
		case 0: return x;
		case 1: return y;
	}
}
vector2 &vector2::operator =  (const vector2 &v){
	x = v.x;
	y = v.y;
	return *this;
}
vector2 &vector2::operator += (const vector2 &v){
	(*this) = (*this) + v;
	return *this;
}
vector2 &vector2::operator -= (const vector2 &v){
	(*this) = (*this) - v;
	return *this;
}
vector2 &vector2::operator *= (float f){
	x *= f;
	y *= f;
	return *this;
}
vector2 &vector2::operator /= (float f){
	x /= f;
	y /= f;
	return *this;
}
bool operator == (const vector2 &a, const vector2 &b){
	return (a.x == b.x) && (a.y == b.y);
}
bool operator != (const vector2 &a, const vector2 &b){
	return !(a == b);
}
vector2 operator - (const vector2 &a){
	vector2 v(-a.x, -a.y);
	return v;
}
vector2 operator + (const vector2 &a, const vector2 &b){
	vector2 v(a.x + b.x, a.y + b.y);
	return v;
}
vector2 operator - (const vector2 &a, const vector2 &b){
	vector2 v(a.x - b.x, a.y - b.y);
	return v;
}
vector2 operator * (const vector2 &v, float f){
	vector2 tmp(v.x * f, v.y * f);
	return tmp;
}
vector2 operator * (float f, const vector2 &v){
	vector2 tmp(v.x * f, v.y * f);
	return tmp;
}
int operator * (const vector2 &a, const vector2 &b){
	return a.x * b.x + a.y * b.y;
}
vector2 operator / (const vector2 &v, float f){
	vector2 tmp(v.x / f, v.y / f);
	return tmp;
}
void vector2::set(float xIn, float yIn){
	x = xIn;
	y = yIn;
}
void vector2::init(float n){
    x = n;
    y = n;
}
void vector2::Min(vector2& a){
    x = min(x, a.x);
    y = min(y, a.y);
}
void vector2::Max(vector2& a){
    x = max(x, a.x);
    y = max(y, a.y);
}
float vector2::length() const{
	return sqrt(x * x + y * y);
}
void vector2::print(FILE *fout) const{
	fprintf(fout, "(%g , %g)", x, y);
}
