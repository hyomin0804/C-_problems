#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,string>> vvv;
vector<int> v,vv;
int a;
string b;
int cnt1,cnt2,temp,ret1,ret2;


int main(){
	cin >> n;
	for(int i=0; i< n; i++){
		cin >> a >> b;
		vvv.push_back({a,b});
	}

	for(auto i: vvv){
		int min = atoi(i.second.substr(0, 2).c_str());
		int sec = atoi(i.second.substr(3).c_str()) + min*60;

		v.push_back(i.first);

		int t= sec - temp;
		vv.push_back(t);
		temp=sec;
	}
	
	vv.push_back(2880-temp);
	
	for(int i=0; i<n+1 ; i++){
		
		if( cnt1 > cnt2){
			ret1+=vv[i];
		}else if( cnt1 < cnt2 ){
			ret2+=vv[i];
		}
		if(v[i]==1) cnt1++;
		else cnt2++;
		
	}

	printf("%02d:%02d\n", ret1/60,ret1%60);
	printf("%02d:%02d\n", ret2/60,ret2%60);

	
	
	return 0;
} 
