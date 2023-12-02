#include <bits/stdc++.h>
using namespace std;
const int INF =987564321;
int n,mp,mf,ms,mv,ret_=INF;
int a,b,c,d,cost;

struct A{
	int cost,a,b,c,d;
};
vector<A> food;

map<int, vector<vector<int>>> ret;

int main(){
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	
	for(int i=0; i<n; i++){
		cin >> a >> b >> c >> d >> cost;
		food.push_back({cost,a,b,c,d});
	}
	
	for(int i=0; i<(1<<n); i++){
		int mmp=0;
		int mmf=0;
		int mms=0;
		int mmv=0;
		int sum=0;
		vector<int> v;
		
		for(int j=0; j<n; j++){
			if(i & (1<<j)){ // 비트마스크의 해당  식재료 번호가 켜져있다면  
				sum+=food[j].cost;
				mmp+=food[j].a;
				mmf+=food[j].b;
				mms+=food[j].c;
				mmv+=food[j].d;
				v.push_back(j+1);
			}
		}
		if(mmp>=mp && mmf>=mf && mms >=ms && mmv>=mv){
			if(ret_>= sum) {
				ret_=sum;
				ret[ret_].push_back(v);
			}
		} 
		
	}
	if(ret_==INF) cout << "-1" <<"\n";
	else {
		sort(ret[ret_].begin(), ret[ret_].end());
		cout << ret_<<"\n";
		for(int i: ret[ret_][0]) cout << i << " ";
	}
	
	return 0;
} 
