//시간 초과  
#include <iostream>
#include <vector>
using namespace std;
int n,a,ret;
vector<int> v;

bool check(int y, int x, int tall){
	for(int i=y+1; i<x; i++){
		if(v[i] > tall) return 0;
	}
	return 1;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);	
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int tall=min(v[i], v[j]) ;
			if(check(i,j,tall)){
				ret++;
			}
		}
	}
	cout << ret;
	return 0;
} 
