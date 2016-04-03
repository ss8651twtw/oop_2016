#include "date.h"
#include <iostream>
using namespace std;
unsigned short int Date::getDate_data()const{
	return Date_data;
}
unsigned short int Date::getDay()const{
	return Date_data & 31;
}
unsigned short int Date::getMon()const{
	return (Date_data & 480) >> 5;
}
unsigned short int Date::getYr()const{
	return 2000 + ((Date_data & (-1 ^ 511)) >> 9);
}
void Date::setDate(const short int& a, const short int& b, const short int& c){
	Date_data = ((a - 2000) << 9) | (b << 5) | c;
}
void Date::showDate(){
	cout << getYr() << " " << getMon() << " " << getDay() << "\n";
}
