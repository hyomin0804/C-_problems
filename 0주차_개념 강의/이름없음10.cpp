#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll n, k, ret, temp1, temp;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k; 
	vector<pair<ll,ll>> v(n);
	vector<ll> vv(k); 
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second; 
	}
	for(int i = 0; i < k; i++) cin >> vv[i]; 
	sort(v.begin(), v.end()); // 보석 크기 작은순으로 정렬 
	sort(vv.begin(), vv.end()); // 가방 크기 작은 순으로 정렬  
	priority_queue<ll> pq; // 내림 차순 자동 정렬됨  
	
	 
	for(int i = 0; i < k; i++){
		int j = 0;
		while(j < n && v[j].first <= vv[i]){
			pq.push(v[j++].second);
		}   // 가격을 넣는다 

		if(pq.size()){ // 큐에 값이 있으면  
			ret += pq.top(); pq.pop(); //결과 값에 더하고 제거  
		}
	} 
	cout << ret << "\n"; 
	return 0;
}     

