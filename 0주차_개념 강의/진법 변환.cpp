#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
	int n =100; // 진법 변환 할 숫자
	int b = 16; // 2진법으로 바꾸기
	while(n>1){
		v.push_back(n%b);
		n/=b;
	} 
	if(n==1)v.push_back(1);
	reverse(v.begin(), v.end()); // 나누고 밑에서 부터 나열해야해서 
	for (int a:v){
		if(a>=10) cout << char(a+55); //if(a>=10) 이건 8진법 위의 16진법 변환을 위해 필요함 
		else cout<<a;
	}
} 
