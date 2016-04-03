#include "date.h"
#include <iostream>
using namespace std;
unsigned short int cnt[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
unsigned short int Date::getDate_data()const{
	return Date_data;
}
unsigned short int Date::getDay()const{
	unsigned short int tmp = Date_data % 366;
	return tmp - cnt[getMon() - 1] + 1;
}
unsigned short int Date::getMon()const{
	unsigned short int tmp = Date_data % 366, stop = 0;
	for(unsigned short int i = 1; i < 13; i++){
		stop = cnt[i];
		if(tmp < stop)return i;
	}
}
unsigned short int Date::getYr()const{
	return 2000 + (Date_data / 366);
}
void Date::setDate(const short int& a, const short int& b, const short int& c){
	Date_data = (a - 2000) * 366 + cnt[b - 1] + c - 1;
}
void Date::showDate(){
	cout << getYr() << " " << getMon() << " " << getDay() << "\n";
}
