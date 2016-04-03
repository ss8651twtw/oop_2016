#ifndef DATE
#define DATE
#include <iostream>
class Date{
	unsigned short int Date_data;
public:
	Date():Date_data(0){}
	unsigned short int getDate_data()const;
	unsigned short int getDay()const;
	unsigned short int getMon()const;
	unsigned short int getYr()const;
	void setDate(const short int&, const short int&, const short int&);
	void showData();
};
#endif
