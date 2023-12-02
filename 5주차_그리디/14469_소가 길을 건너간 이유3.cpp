#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int a,b,ret;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	sort(v.begin(),v.end());
	
	for(auto now : v){
		if(ret >= now.first){
			ret+=now.second;
		}else if(ret < now.first){
			ret=now.first+now.second;
		}
		
	}
	cout << ret;
	return 0;
} 
