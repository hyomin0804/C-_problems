#include <bits/stdc++.h>
using namespace std;
int n,ret=0;
int a[1001], cnt[1001];

int main() {
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(int i=0; i<n; i++){
		int maxValue=0; 	
		for(int j=0; j<i; j++){
			if( a[i] > a[j] && maxValue < cnt[j]) { // a[i]�� ������ �ϴ� ������� ���� ã��  
				maxValue=cnt[j]; 
			}
		}
		cnt[i] = maxValue+1; // cnt[i] ���� maxvalue�� +1 
		ret=max(ret, cnt[i]);

	}
	
	cout << ret;
	/*
	for(int i : ret){
		cout<< i << " ";
	}
	*/
	
	return 0;
} 


