#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int mp[1000000];
stack<int> stk;

int main(){
	cin >> n;
	memset(mp,-1,sizeof(mp));
	
	for(int i=0; i< n; i++){
		cin >> a[i];
		while (stk.size() && a[stk.top()] < a[i] ){
			mp[stk.top()]=a[i];
			stk.pop();
		}
		stk.push(i);
		
	}
	
	for(int i=0; i<n; i++) cout << mp[i] << " ";
	return 0;
} 
