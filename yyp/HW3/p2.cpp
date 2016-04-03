#include "date.h"
#include <iostream>
using namespace std;
int main(){
	short int y, m, d;
	Date date;
	cin >> y >> m >> d;
	cout << date.getDate_data() << "\n";
	date.setDate(y, m, d);
	cout << date.getDate_data() << "\n";
	date.showData();
}
