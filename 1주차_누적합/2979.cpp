#include <bits/stdc++.h>
using namespace std;

int t[101];
int a,b,c,d,e, sum;

int main(){
	cin >> a >> b >> c;
	for(int i=0; i<3; i++){
		cin >> d >> e;
		for (int i=d; i<e; i++) t[i]++; // �ð��� �̻� �̸� [ , } 
	}
	for (int i : t){
		if (i==1) sum+=a;
		if (i==2) sum+=2*b;
		if (i==3) sum+=3*c;
	}
		
	cout << sum;
} 
