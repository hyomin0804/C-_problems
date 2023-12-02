#include <bits/stdc++.h>
using namespace std;
int n,t,x,l,r,ret;
vector<int> a;

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> t;
		a.push_back(t);
	}

	cin >> x;
	
	l=0;
	r=n-1;
	sort(a.begin(), a.end());
	while(l<r){
		if(a[l]+a[r]==x) r--, ret++;
		else if(a[l]+a[r]<x) l++;
		else if(a[l]+a[r]>x) r--;
	}
	
	cout << ret <<"\n";
	
	
	return 0;
} 
