#include <bits/stdc++.h>
using namespace std;
int T,n,m;

bool check(vector<int> &a, int i){
	
	int l=0;
	int r= a.size()-1;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>i) r=mid-1;
		else if(a[mid]==i) return 1;
		else l=mid+1;
	}
	
	return 0;
}

int main(){
	cin >> T;
	
	while(T--){
		cin >>  n;
		vector<int> a(n);
		
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		cin >>  m;
		
		vector<int> b(m);
		
		for(int i=0; i<m; i++){
			cin >> b[i];
		}
		
		sort(a.begin(),a.end());

		for(int i : b)
		cout << check(a, i) <<"\n";
		
	}
	
	
	return 0;
}
