#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a, ret=1e18;

//현재 설정된 mid 값을 기준으로 보석을 학생들에게 나눠주었을 때, 
//가장 많은 보석을 가진 학생의 보석 수가 n 이하인지를 판단하는 것
//보석 상자 나눠서 카운팅  
bool check(ll mid){ 
	ll num=0; // 그룹 크기  
	for(int i=0; i<m; i++){ //보석마다 그룹 몇개 만들어지는지 표시  
		num+=a[i]/mid; // mid 값으로 나눠진 몴,  보석의 총 그룹 수  
		if(a[i]%mid) num++;// 나머지 있으면 추가 +1 
	}
	return n>=num; // 학생수가 항상 그룹수보다 커야함. 그래야 나눠줄 수 있음  
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	
	cin >>n >>m;
	ll lo=1, hi=0, mid; // 질투값의 최소=1 부터 시작  
	vector<int> v;
	for(int i=0; i<m; i++){
		cin >> a;
		v[i].push_back(a);
		hi=max(hi, a[i]) // 보석 중 가장 개수가 많은 것  
	}
	while(lo<=hi){
		mid=(lo+hi)/2; // 이 mid 값으로 학생들에게 나눠줌  
		
		if (check(mid)){ // 해당 최솟값으로 나눠줄 수있는지 검사  
			ret=min(ret,mid))// 질투심 최소 찾기  
			hi=mid-1;
		} else lo=mid+1
	}
	
	cout << ret << "\n";	
	
	return 0;
} 
