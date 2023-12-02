#include <bits/stdc++.h>
using namespace std;
int n,from,to, t,f;
vector<pair<int,int>> a;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> from >> to;
		a.push_back({to, from});
	}
	sort(a.begin(), a.end());
	t= a[0].first; //to
	f= a[0].second; //from
	int ret=1;
	for(int i=1; i<n; i++){
		if( t > a[i].second) continue;
		t= a[i].first; f=a[i].second; ret++;
		
	}
	cout << ret << '\n';
	
	return 0;
}
