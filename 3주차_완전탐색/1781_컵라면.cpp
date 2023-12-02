#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, a, b,ret;

int main(){
	cin >> n;
	vector<pair<ll,ll>> v(n);
		
	for(int i=1; i<n+1; i++){
		cin >> a >> b;
		v.push_back({a,b}); // 데드라인, 컵라면  
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<v.size(); i++){
		ret+=v[i].second;
		pq.push(v[i].second);
		if(pq.size()>v[i].first){
			ret -=pq.top();
			pq.pop();
		}
	}
	
	cout << ret << "\n";
	
	return 0;
	
} 
