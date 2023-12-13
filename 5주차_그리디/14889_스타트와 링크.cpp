#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int n,ret=987654321; 
int mp[20][20];
vector<vector<int>> vv;

int go(vector<int> v1, vector<int> v2){
	pair<int,int> ret; // start와 link 경쟁력 담을 결과 변수 
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			if(i==j) continue;
			ret.first+=mp[v1[i]][v1[j]];
			ret.second+=mp[v2[i]][v2[j]];
		}
	} 
	return abs(ret.first-ret.second);
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		cin >> mp[i][j];
		}
	}
	
	for(int i=0; i<(1<<n); i++){
		if(__builtin_popcount(i)==n/2){
			vector<int> v1,v2;
			for(int j=0; j<n; j++){
				if(i & (1<<j)){
					v1.push_back(j);
				}else{
					v2.push_back(j);
				}
			}
			ret= min(ret,go(v1,v2));
		}
	}

	cout << ret << "\n";
	return 0;
} 
