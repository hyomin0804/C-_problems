#include <bits/stdc++.h>
using namespace std;
int n, temp,sum;
vector<int> v;

bool check (int n) { // 소수 체크 함수 
	if(n<=1) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	for(i int=2; i*i<=n;i++){
		if(n%i==0) return 0;
	}
	
	return 1;
	
}

int go(int idx, int sum){
	if (ind ==n){ // 모든 인덱스를 탐색이 끝났다면 
		return check(sum);
	}
	return go(idx+1, sum+v[idx]))+ go(idx+1,sum);
	        // 수 포함 O                 // 수 제외 X
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> temp
		v.push_back(temp)
	}
	
	cout << go(0,0) << "\n";
	
	retrn 0;
}
