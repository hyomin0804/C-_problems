
#include <bits/stdc++.h>
using namespace std;
int n,m,a,cnt;
vector<int> v;

int main(){
	cin >> n >> m;
	
	if(m<=2 || m > 200000){
		cout << 0;
		exit(0);
	} 

	for (int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	
	for(int i=0; i<v.size();i++){
		for(int j=i+1; j<n; j++){
			if(v[i]+v[j]==m){
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}

