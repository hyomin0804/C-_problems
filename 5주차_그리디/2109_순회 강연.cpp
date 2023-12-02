#include <bits/stdc++.h>
using namespace std;
int n,p,d,f,s,ret;

vector<pair<int,int>> v; 
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순  
int main(){
	cin >>n; // 학교 수  
	for(int i=0; i<n; i++){
		cin >> p >> d ;
		v.push_back({d,p}); // 기간 순으로 정렬할거여서 반대로 넣어야함  
	}
	sort(v.begin(), v.end()); // 일정 짧, 비용 작은 순으로 오름차순  
	
	for(int i =0; i<n; i++){
		pq.push(v[i].second);
		if(pq.size() > v[i].first) { // 그리디, 최대 찾고 최소 빼기  
			pq.pop();
		}
	}

	while(!pq.empty()){
		
		ret+=pq.top(); pq.pop();
		
	}
	cout << ret <<"\n";
	
	return 0;

} 
