/*
// 시간 초과  
#include <bits/stdc++.h>
using namespace std;
int t,n,m,aa,bb,cnt;


int main(){
	cin >> t;
	while(t--){
		cnt=0;
		vector <int> a,b;
		cin >> n >> m;
		
		for(int i=0; i<n; i++){
			cin >> aa;
			a.push_back(aa);
		}
		for(int i=0; i<m; i++){
			cin >> bb;
			b.push_back(bb);
		}
		
		for( int a_ : a){
			for(int b_ : b){
				if(a_>b_) cnt++;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
} 
*/

// upper_bound 사용!! 
#include <bits/stdc++.h>
using namespace std;
int t,n,m,aa,bb,cnt;


int main(){
	cin >> t;
	while(t--){
		cnt=0;
		vector<int> a,b;
		cin >> n >> m;
		
		for(int i=0; i<n; i++){
			cin >> aa;
			a.push_back(aa);
		}
		for(int i=0; i<m; i++){
			cin >> bb;
			b.push_back(bb);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		for(int i : b){
			int k= upper_bound(a.begin(),a.end(),i)-a.begin();
			cnt+=a.size()-k;
		}
		cout << cnt << "\n";
	}
	
	return 0;
} 
