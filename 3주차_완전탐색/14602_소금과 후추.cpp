#include <bits/stdc++.h>
using namespace std;
int n,m,mx,w;
int mp[30][30];
vector<int> v, ret[30];

int main(){
	cin >> n >> m>> mx >> w;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mp[i][j];
		}
	}
	
	
	for(int k=0; k< (n-w+1) ;k++){
		for(int l=0; l< (m-w+1) ;l++){
			for(int i=k; i<w+k; i++){
				for(int j=l; j<w+l; j++){
					v.push_back(mp[i][j]);
				}
			}
			sort(v.begin(), v.end());
			int mid=v.size()/2;
			ret[k].push_back(v[mid]);
			v.clear();
		}
		
	}
	
	for(int i=0; i< (n-w+1) ; i++){
		for( int j: ret[i]){
			cout << j << " ";
		}
		cout << "\n";
	}
	
	
	return 0;
} 
