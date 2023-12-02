#include<bits/stdc++.h>
using namespace std;
# 최소 공배수 / 최대 공약수 
int gcd(int a, int b){
if(a == 0) return b;
return gcd(b % a, a);
}
int lcm(int a, int b){
return (a * b) / gcd(a, b);
}

int main(){
	int a=10, b=12;
	cout << lcm(a,b) <<"\n";
	cout << gcd(a,b) <<"\n";
	return 0;
}

