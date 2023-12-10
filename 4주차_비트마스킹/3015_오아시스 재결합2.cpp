#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
ll n,a,ret;
stack<pair<ll,ll>> stk;

int main(){
	cin >> n;
	
	for(int i=0; i<n; i++){
		int cnt=1;
		cin >> a;
		while(stk.size() && stk.top().first<=a){ // 오름차순  
			ret+=stk.top().second; 
			if(stk.top().first==a){
				cnt=stk.top().second +1;
			}else{
				cnt=1;
			}
			
			stk.pop();
			
		}
		if(stk.size()) ret++;
		stk.push({a,cnt});
	
		
	}
	cout << ret << "\n"; 
	return 0;
} 
