#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
ll n,a,b,ret;
vector<pair<ll,ll>> v;

bool cmp(pair<ll,ll> a,pair<ll,ll> b ){
	
	if(a.second == b.second ){
		return a.first < b.first; // ���� �ð� �������� *** 
	}else return a.second < b.second; // ������ �ð��� ��������  
	
}
int main(){
	cin >>n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end(),cmp);
	
	int cnt=0; // ���� �ð� , �귯���� �ð�  
	for(auto i: v){
		if(cnt <= i.first){
			ret++;
			cnt=i.second;
		}
	}
	
	cout << ret;
	
	return 0;
} 
