#include <bits/stdc++.h>
using namespace std;
int n,p,d,f,s,ret;

vector<pair<int,int>> v; 
priority_queue<int, vector<int>, greater<int>> pq; // ��������  
int main(){
	cin >>n; // �б� ��  
	for(int i=0; i<n; i++){
		cin >> p >> d ;
		v.push_back({d,p}); // �Ⱓ ������ �����Ұſ��� �ݴ�� �־����  
	}
	sort(v.begin(), v.end()); // ���� ª, ��� ���� ������ ��������  
	
	for(int i =0; i<n; i++){
		pq.push(v[i].second);
		if(pq.size() > v[i].first) { // �׸���, �ִ� ã�� �ּ� ����  
			pq.pop();
		}
	}

	while(!pq.empty()){
		
		ret+=pq.top(); pq.pop();
		
	}
	cout << ret <<"\n";
	
	return 0;

} 
