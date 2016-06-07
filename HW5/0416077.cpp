#include <cstdio>
#include <list>
#include <vector>
#include <cfloat>
#include "0416077_vector2.h"
#include "0416077_vector3.h"
#define PB push_back
using namespace std;
FILE *fin, *fout;
template <class T, class S>
void GetCenter(T vbegin, T vend, S& center){
    center.init(0);
    int tol = 0;
    for(T itr = vbegin; itr != vend; itr++)center += *itr, tol++;
    center /= tol;
    fprintf(fout, "\nThe center of the list is ");
    center.print(fout);
    fputs("\n", fout);
}
template <class T, class S>
void BoundingBox(T vbegin, T vend, S& r, S& b){
    r.init(FLT_MAX);
    b.init(FLT_MIN);
    for(T itr = vbegin; itr != vend; itr++){
        r.Min(*itr);
        b.Max(*itr);
    }
    fprintf(fout, "The bounding box of the list is ");
    r.print(fout);
    fprintf(fout, " - ");
    b.print(fout);
    fputs("\n\n", fout);
}
template <class T>
void Print(T vbegin, T vend){
    for(T itr = vbegin; itr != vend; itr++){
        itr->print(fout);
        fputs("\n", fout);
    }
}
int main(){
    // vector2 and vector3 are points in 2D and 3D, respectively
	list<vector2> x1;
	list<vector3> x2;
	vector<vector2> v1;
	vector<vector3> v2;

	// read data from file
	// ...
	fin = fopen("Input.txt", "r");
	fout = fopen("Output.txt", "w");
	vector2 tmp2;
	vector3 tmp3;
	for(int i = 0; i < 10; i++){
        fscanf(fin, "(%g , %g)\n", &tmp2.x, &tmp2.y);
        x1.PB(tmp2);
	}
	for(int i = 0; i < 10; i++){
        fscanf(fin, "(%g , %g , %g)\n", &tmp3.x, &tmp3.y, &tmp3.z);
        x2.PB(tmp3);
	}
	for(int i = 0; i < 10; i++){
        fscanf(fin, "(%g , %g)\n", &tmp2.x, &tmp2.y);
        v1.PB(tmp2);
	}
	for(int i = 0; i < 10; i++){
        fscanf(fin, "(%g , %g , %g)\n", &tmp3.x, &tmp3.y, &tmp3.z);
        v2.PB(tmp3);
	}

	vector2 r2 , b2;
	vector3 r3 , b3;

	Print(x1.begin() , x1.end());
	GetCenter(x1.begin() , x1.end() , r2);
	BoundingBox(x1.begin() , x1.end() , r2 , b2);

    Print(x2.begin() , x2.end());
	GetCenter(x2.begin() , x2.end() , r3);
	BoundingBox(x2.begin() , x2.end() , r3 , b3);

	Print(v1.begin() , v1.end());
	GetCenter(v1.begin() , v1.end() , r2);
	BoundingBox(v1.begin() , v1.end() , r2 , b2);

	Print(v2.begin() , v2.end());
	GetCenter(v2.begin() , v2.end() , r3);
	BoundingBox(v2.begin() , v2.end() , r3 , b3);

	fclose(fin);
	fclose(fout);
}
