#include <bits/stdc++.h>
using namespace std;

int a[9];
vector<int> v;
int sum =0;
pair<int,int> ret;

void solve(){
	for(int i=0; i<9; i++){
		for(int j=0; j<i; j++){
			if(sum-a[i]-a[j]==100){
				ret = {i,j}; // 값이 아닌 인덱스를 저장 
				return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for(int i=0; i<9; i++){
		cin >> a[i]; 
		cout << '\n';
		sum +=a[i];
	} 
	solve();
	cout <<"ret.first: "<< a[ret.first] << " ret.second: " << a[ret.second];
	cout << '\n';
	
	for(int i=0; i<9; i++){
		if(ret.first==i || ret.second==i) continue;
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());	
	
	for(int i: v) cout << i << "\n";
	return 0;
}
