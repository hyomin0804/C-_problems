#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
ll n,a,b,ret;
vector<pair<ll,ll>> v;

bool cmp(pair<ll,ll> a,pair<ll,ll> b ){
	
	if(a.second == b.second ){
		return a.first < b.first; // 시작 시간 오름차순 *** 
	}else return a.second < b.second; // 끝나는 시간은 오름차순  
	
}
int main(){
	cin >>n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end(),cmp);
	
	int cnt=0; // 시작 시간 , 흘러가는 시간  
	for(auto i: v){
		if(cnt <= i.first){
			ret++;
			cnt=i.second;
		}
	}
	
	cout << ret;
	
	return 0;
} 
