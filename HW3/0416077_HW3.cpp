#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
template <class T> 
void sortNumber(T& a, int n){
	sort(a, a + n);
}
class HugeInteger{
	char val[255];
public:
	HugeInteger(){}
	HugeInteger(char *s){
		strcpy(val, s);
	}
	bool operator<(const HugeInteger& x){
		int l1 = strlen(val), l2 = strlen(x.val);
		if(l1 < l2)return 1;
		if(l1 > l2)return 0;
		return strcmp(val, x.val) < 0 ? 1 : 0;
	}
	friend ostream& operator<<(ostream& os, HugeInteger& x){
		return os << x.val;
	}
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int val[10] = {11 , 32 , 5 , 8 , 2 , 10 , 23 , 87 , 12 , 2};
	sortNumber(val , 10);
	for (int i = 0 ; i < 10 ; i++)
		cout << val[i] << " ";
	cout << endl;
	HugeInteger huge[6] = {"12087" , "1389" , "99783" , "870843" , "3338765" , "93673"};
	sortNumber(huge , 6);
	for (int i = 0 ; i < 6 ; i++)
		cout << huge[i] << " ";
	cout << endl;
}
