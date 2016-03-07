#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MAX_LEN 1000
using namespace std;
class HugeInteger{
public:
	HugeInteger();
	~HugeInteger();
	void setValue(char *input);					// val = input
	const char* getValue() const;				// return val
	void print();
	void Add(const HugeInteger H1, const HugeInteger H2);			// val = H1 + H2
	void Substract(const HugeInteger H1, const HugeInteger H2);	// val = H1 - H2
	void Multiply(const HugeInteger H1, const HugeInteger H2);		// val = H1 * H2
	void Divide(const HugeInteger H1, const HugeInteger H2);		// val = H1 / H2
	void Divide(const HugeInteger H1, const int r);
private:
	char val[MAX_LEN];
};
HugeInteger::HugeInteger(){
	memset(val,0,sizeof(val));
}
HugeInteger::~HugeInteger(){
	memset(val,0,sizeof(val));
}
void HugeInteger::setValue(char *input){
	strcpy(val,input);
}
const char* HugeInteger::getValue() const{
	return val;
}
void HugeInteger::print(){
	puts(val);
}
bool cmp(const char *a,const char *b){
	int len1=strlen(a),len2=strlen(b);
	if(len1<len2)return true;
	if(len1>len2)return false;
	for(int i=0;i<len1;i++){
		if(a[i]<b[i])return true;
		if(a[i]>b[i])return false;
	}
	return false;
}
void change(int *s, const char *old){
	int len=strlen(old);
	for(int i=len-1,j=0;i>=0;i--,j++)
		s[j]=old[i]-'0';
}
void change(char *s, int *old){
	int i=MAX_LEN-1;
	while(i>=0&&!old[i])i--;
	if(i==-1){
		s[0]='0';
		return;
	}
	for(int j=0;i>=0;i--,j++)
		s[j]=old[i]+'0';
}
void HugeInteger::Add(const HugeInteger H1, const HugeInteger H2){
	const char *a = H1.getValue();
	const char *b = H2.getValue();
	int an[MAX_LEN]={0}, bn[MAX_LEN]={0}, cn[MAX_LEN]={0};
	change(an,a);
	change(bn,b);
	int al=strlen(a), bl=strlen(b);
	int m=max(al, bl);
	for(int i=0;i<m;i++)cn[i]=an[i]+bn[i];
	for(int i=0;i<MAX_LEN;i++)
		if(cn[i]>9){
			cn[i+1]+=cn[i]/10;
			cn[i]%=10;
		}
	char ans[MAX_LEN]={0};
	change(ans, cn);
	setValue(ans);
}
void HugeInteger::Substract(const HugeInteger H1, const HugeInteger H2){
	const char *a = H1.getValue();
	const char *b = H2.getValue();
	bool f=0;
	if(cmp(a, b)){
		swap(a, b);
		f=1;
	}
	int an[MAX_LEN]={0}, bn[MAX_LEN]={0}, cn[MAX_LEN]={0};
	change(an,a);
	change(bn,b);
	int al=strlen(a), bl=strlen(b);
	for(int i=0;i<al;i++)cn[i]=an[i]-bn[i];
	for(int i=0;i<MAX_LEN;i++)
		if(cn[i]<0){
			cn[i]+=10;
			cn[i+1]--;
		}
	char ans[MAX_LEN]={0};
	if(f){
		ans[0]='-';
		change(ans+1, cn);
	}
	else change(ans, cn);
	setValue(ans);
}
void HugeInteger::Multiply(const HugeInteger H1, const HugeInteger H2){
	const char *a = H1.getValue();
	const char *b = H2.getValue();
	int an[MAX_LEN]={0}, bn[MAX_LEN]={0}, cn[MAX_LEN]={0};
	change(an,a);
	change(bn,b);
	int al=strlen(a), bl=strlen(b);
	for(int i=0;i<al;i++)
		for(int j=0;j<bl;j++)
			cn[i+j]+=an[i]*bn[j];
	for(int i=0;i<MAX_LEN;i++)
		if(cn[i]>9){
			cn[i+1]+=cn[i]/10;
			cn[i]%=10;
		}
	char ans[MAX_LEN]={0};
	change(ans, cn);
	setValue(ans);
}
void HugeInteger::Divide(const HugeInteger H1, const HugeInteger H2){
	const char *a = H1.getValue();
	const char *b = H2.getValue();
	char s[MAX_LEN];
	int an[MAX_LEN]={0}, bn[MAX_LEN]={0}, cn[MAX_LEN]={0};
	change(an,a);
	change(bn,b);
	int al=strlen(a), bl=strlen(b);
	if(cmp(a, b)){
		setValue("0");
		return;
	}
	HugeInteger l,r;
	char tmp[]="1";
	l.setValue(tmp);
	strcpy(s,H1.getValue());
	r.setValue(s);
	while(cmp(l.getValue(), r.getValue())){
		HugeInteger mid,tmp;
		tmp.Add(l, r);
		mid.Divide(tmp, 2);
		if(!strcmp(mid.val,l.val))break;
		tmp.Multiply(mid, H2);
		if(!strcmp(tmp.getValue(),H1.getValue())){
			memset(s,0,sizeof(s));
			strcpy(s,mid.getValue());
			l.setValue(s);
			break;
		}
		strcpy(s,mid.getValue());
		if(cmp(tmp.getValue(),a))l.setValue(s);
		else r.setValue(s);
	}
	strcpy(s,l.getValue());
	setValue(s);
}
void HugeInteger::Divide(const HugeInteger H1, const int r){
	const char *a=H1.getValue();
	char ans[MAX_LEN]={0};
	int len=strlen(a),tmp=0,j=0;
	for(int i=0;i<len;i++){
		tmp=tmp*10+a[i]-'0';
		if(tmp>=r){
			ans[j++]=tmp/r+'0';
			tmp%=r;
		}
		else if(j&&tmp<r)ans[j++]='0';
	}
	setValue(ans);
}
int main(){
	HugeInteger A, B, C;
	char buffer[2][MAX_LEN], oper;
	while(cin >> buffer[0] >> oper >> buffer[1]){
		A.setValue(buffer[0]);
		B.setValue(buffer[1]);
		if(oper=='+')C.Add(A, B);
		else if(oper=='-')C.Substract(A, B);
		else if(oper=='*')C.Multiply(A, B);
		else if(oper=='/')C.Divide(A, B);
		C.print();
	}
}
