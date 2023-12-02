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
	sort(J.begin(),J.end(),greater<pair<ll, ll>>()); // ���� ū ������ sort 
	sort(bag, bag+k);
	
	//priority_queue<ll> pq; //�켱 ���� ť�� �߾� �ϴ� �־�!! �̷� ������ ����.  
	cout <<"\n";
	for (int j=0; j<J.size(); j++){
		cout << J[j].first << ", " << J[j].second <<"\n"; 
	}
	cout <<"\n";
	for(int i : bag){
		for( int j=0; j<J.size(); j++){
			if(i >= J[j].second){
				cout << i << "ũ���� ���濡" << J[j].second << ", " << J[j].first << "\n";
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
	vector<pair<ll,ll>> v(n); // ������ ���� (����, ����)
	vector<ll> bag(k); // ������ ����  
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	for(int i = 0; i < k; i++) cin >> bag[i]; 
	sort(v.begin(), v.end()); // ������������ ���� ����  
	sort(bag.begin(), bag.end()); // ���� ũ�� ��->ū �������� ����  
	priority_queue<ll> pq; 
	
	int j = 0; 
	for(int i = 0; i < k; i++){ //������ ������ŭ �ݺ�  
		while(j < n && v[j].first <= bag[i]) pq.push(v[j++].second); //���԰� ���� ���� �ͺ��� �ֱ� 
		if(pq.size()){
			ret += pq.top(); pq.pop();
		}
	} 
	cout << ret << "\n"; 
	return 0;
}     
