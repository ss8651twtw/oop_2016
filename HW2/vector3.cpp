#include "vector3.h"
vector3::vector3(float inX, float inY, float inZ){
	x=inX;
	y=inY;
	z=inZ;
}
vector3::vector3(const vector3 &v){
	x=v.x;
	y=v.y;
	z=v.z;
}
float &vector3::operator [] (unsigned int index){
	switch(index){
		case 0:return x;
		case 1:return y;
		case 2:return z;
	}
}
const float &vector3::operator [] (unsigned int index) const{
	switch(index){
		case 0:return x;
		case 1:return y;
		case 2:return z;
	}
}
vector3 &vector3::operator =  (const vector3 &v){
	x=v.x;
	y=v.y;
	z=v.z;
	return *this;
}
vector3 &vector3::operator += (const vector3 &v){
	(*this)=(*this)+v;
	return *this;
}
vector3 &vector3::operator -= (const vector3 &v){
	(*this)=(*this)-v;
	return *this;
}
vector3 &vector3::operator *= (float f){
	x*=f;
	y*=f;
	z*=f;
	return *this;
}
vector3 &vector3::operator /= (float f){
	x/=f;
	y/=f;
	z/=f;
	return *this;
}
bool operator == (const vector3 &a, const vector3 &b){
	return (a.x==b.x)&&(a.y==b.y)&&(a.z==b.z);
}
bool operator != (const vector3 &a, const vector3 &b){
	return !(a==b);
}
vector3 operator - (const vector3 &a){
	
}
vector3 operator + (const vector3 &a, const vector3 &b){
	vector3 v(a.x+b.x,a.x+b.x,a.x+b.x);
	return v;
}
vector3 operator - (const vector3 &a, const vector3 &b){
	vector3 v(a.x-b.x,a.x-b.x,a.x-b.x);
	return v;
}
vector3 operator * (const vector3 &v, float f){
	vector3 tmp(v.x*f,v.y*f,v.z*f);
	return tmp;
}
vector3 operator * (float f, const vector3 &v){
	vector3 tmp(v.x*f,v.y*f,v.z*f);
	return tmp;
}
vector3 operator / (const vector3 &v, float f){
	vector3 tmp(v.x/f,v.y/f,v.z/f);
	return tmp;
}
