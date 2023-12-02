/*
#include <bits/stdc++.h>
using namespace std;
int n;
int a[]={1,2,4,8,16,32,64};
int main(){
	cin >> n;
	for(int i=0; i<(1<<7); i++){
		int cnt=0;
		int sum=0;
		for(int j=0; j<7; j++){
			if(i & (1<<j)){
				sum+=a[j];
				cnt++;
			}
		}
		if(sum==n) {
			cout << cnt;
			break;
		}
		
	}
	
	return 0;
} 
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	
	cin >> n;
	cout << __builtin_popcount(n);
	
	
	return 0;
}
