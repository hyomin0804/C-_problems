#include <bits/stdc++.h>
using namespace std;

//소수는 1, 소수가 아닌 정수는 0 반환 
bool check(int n){
	if(n<=1) return 0;
	if(n==2) return 1;
	if(n % 2 ==0) return 0;
	for (int i =2; i*i <=n; i++){
		if (n%i==0) return 0;
	}
	return 1;
} 
 
int main(){
	for(int i =1; i<20; i++){
		if(check(i)){
			cout<< i<< "는 소수 입니다.\n";
		}
	}
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

const int max_n =40;
bool che[max_n+1]; // bool로 표시하기 때문에 40까지면 41 부터 거짓을 출력해야해서

//소수 출력 함수 
vector<int> era(int mx_n){ 
	vector<int> v;
	for(int i=2; i<=max_n; i++){
		if(che[i]) continue;
		for (int j=2*i; j<= mx_n; j+=i){ //공약수 있는 수는 모두 빼는 코드 
			che[j]=1;
		}
	}
	for(int i =2; i <=max_n; i++) if(che[i]==0) v.push_back(i);
	return v;
}

int main(){
	vector<int> a = era(max_n);
	for(int i : a ) cout<< i << " ";
}
*/



