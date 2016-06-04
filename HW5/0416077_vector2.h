#include <cstdio>
using namespace std;

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class vector2
{
public:
	/* data members */
	float x, y;

	//****************************************************//
	//  You need to implement the following functions !!  //
	//****************************************************//

public:
	/* constructors */
	// default constructor -- don't do anything with it
	vector2() {};

	// constructor with initializing float values
	vector2(float inX, float inY);

	// constructor with initializing vector2
	vector2(const vector2 &v);

public:
	/* Operators */

	// access element
	float                 &operator [] (unsigned int index);
	const float           &operator [] (unsigned int index) const;

	vector2               &operator =  (const vector2 &v);
	vector2               &operator += (const vector2 &v);
	vector2               &operator -= (const vector2 &v);
	vector2               &operator *= (float f);
	vector2               &operator /= (float f);
	friend bool           operator == (const vector2 &a, const vector2 &b);
	friend bool           operator != (const vector2 &a, const vector2 &b);
	friend vector2        operator - (const vector2 &a);
	friend vector2        operator + (const vector2 &a, const vector2 &b);
	friend vector2        operator - (const vector2 &a, const vector2 &b);
	friend vector2        operator * (const vector2 &v, float f);
	friend vector2        operator * (float f, const vector2 &v);
	friend int            operator * (const vector2 &a, const vector2 &b);
	friend vector2        operator / (const vector2 &v, float f);

 public:
	 /* Methods */

	 // set values (e.g. x = xIn, ...)
	 void set(float xIn, float yIn);
     void init(float n);
     void Min(vector2& a);
     void Max(vector2& a);

	 // calculate length
	 float length() const;

	  // print matrix using std::cout
	 void print(FILE *fout) const;
};

#endif
