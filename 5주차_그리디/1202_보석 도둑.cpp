/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,m,v,c,ret;
vector<pair<ll,ll>> J;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> m >> v;
		J.push_back({v,m});
	}
	int bag[k];
	
	for (int i=0; i<k; i++){
		cin >> bag[i];
		
	}
	sort(J.begin(),J.end(),greater<pair<ll, ll>>()); // 가격 큰 순으로 sort 
	sort(bag, bag+k);
	
	//priority_queue<ll> pq; //우선 순위 큐는 야야 일단 넣어!! 이런 문제가 많다.  
	cout <<"\n";
	for (int j=0; j<J.size(); j++){
		cout << J[j].first << ", " << J[j].second <<"\n"; 
	}
	cout <<"\n";
	for(int i : bag){
		for( int j=0; j<J.size(); j++){
			if(i >= J[j].second){
				cout << i << "크기의 가방에" << J[j].second << ", " << J[j].first << "\n";
				ret+=J[j].first;
				J.erase(J.begin() + j);
				break;
			}   
		}
		
	}
	
	cout << ret << "\n";
	
	return 0;
} */

#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll n, k, ret, temp1, temp;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k; 
	vector<pair<ll,ll>> v(n); // 보석의 개수 (무게, 가격)
	vector<ll> bag(k); // 가방의 개수  
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	for(int i = 0; i < k; i++) cin >> bag[i]; 
	sort(v.begin(), v.end()); // 오름차순으로 무게 정렬  
	sort(bag.begin(), bag.end()); // 가방 크기 작->큰 오른차순 정렬  
	priority_queue<ll> pq; 
	
	int j = 0; 
	for(int i = 0; i < k; i++){ //가방의 개수만큼 반복  
		while(j < n && v[j].first <= bag[i]) pq.push(v[j++].second); //무게가 가장 작은 것부터 넣기 
		if(pq.size()){
			ret += pq.top(); pq.pop();
		}
	} 
	cout << ret << "\n"; 
	return 0;
}     
