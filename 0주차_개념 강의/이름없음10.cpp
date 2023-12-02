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
	sort(v.begin(), v.end()); // ���� ũ�� ���������� ���� 
	sort(vv.begin(), vv.end()); // ���� ũ�� ���� ������ ����  
	priority_queue<ll> pq; // ���� ���� �ڵ� ���ĵ�  
	
	 
	for(int i = 0; i < k; i++){
		int j = 0;
		while(j < n && v[j].first <= vv[i]){
			pq.push(v[j++].second);
		}   // ������ �ִ´� 

		if(pq.size()){ // ť�� ���� ������  
			ret += pq.top(); pq.pop(); //��� ���� ���ϰ� ����  
		}
	} 
	cout << ret << "\n"; 
	return 0;
}     

