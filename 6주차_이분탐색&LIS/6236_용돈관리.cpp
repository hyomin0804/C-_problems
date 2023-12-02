#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b;
ll lo,hi;
ll sum,cnt;

vector<ll> a;

bool check(int mid){
	sum=mid;
	cnt=1;
	for(int i: a){

		if( sum >= i ) sum-=i;
		else{
			sum=mid;
			cnt++;
			sum-=i;
		}
	}
	return m >=cnt;
}



int main() {
	
	cin >> n >> m; 
	for(int i=0; i<n; i++){
		cin >> b;
		a.push_back(b);
		lo=max(lo, b);
		hi+=b;
	}
	
	ll ret=hi;
	
	while(lo<=hi){
		ll mid= (lo+hi)/2;
		
		if(check(mid)){
			ret=min(ret, mid);
			hi=mid-1;
			
		}else lo=mid+1;
	}
	
	 cout << ret << "\n";
	
	
	return 0;
} 
