#include <bits/stdc++.h>
using namespace std;
int n,m,a;
map<int,int> mp, mp_first;

bool cmp(pair<int,int> a, pair<int,int> b){
	if( a.first==b.first) {
		return mp_first[a.second] <mp_first[b.second]; // 오름 차순   
	}
	return a.first > b.first; // 내림 차순  
}

int main (){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a;
		mp[a]++;
		if(mp_first[a]==0) mp_first[a]=i+1; //초기화가 0으로 일어나므로 +1  
	}
	vector<pair<int,int>> v;
	
	for( auto i : mp){
		v.push_back({i.second, i.first}); // 빈도 수, 숫자  
	}
	sort(v.begin(),v.end(), cmp);
	
	for(auto i: v){
		for(int j=0; j<i.first; j++){
			cout << i.second << " ";
		}
	}
} 
