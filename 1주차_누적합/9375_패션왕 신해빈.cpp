#include <bits/stdc++.h>
using namespace std;
int t,k;
string a,b;


int main(){
	cin >> t;
	while (t--){
		map<string,int> mp;
		int sum=1;
		
		cin >> k;
		
		for(int i=0; i<k; i++){
		cin >> a >> b;
		mp[b]+=1;
		}
		
		for(auto a: mp){
			sum*=(a.second+1);
		}
		
		cout << sum-1 << "\n";
	}
	
	
	return 0;
}
 
