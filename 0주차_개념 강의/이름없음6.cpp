#include <bits/stdc++.h>
using namespace std;
 map<int, vector<vector<int>>> ret_v;

int main(){
	ret_v.insert({100, {{6,7}}});
	ret_v[100].push_back({0,1});
	ret_v[100].push_back({1,2});
	sort(ret_v[100].begin(), ret_v[100].end());
	for(int a: ret_v[100][0]){
			cout << a <<" "; // 최소 번호  
		}
		cout << "\n";
		for(int a: ret_v[100][1]){
			cout << a <<" "; // 최소 번호  	
		}
		cout << "\n";
		for(int a: ret_v[100][2]){
			cout << a <<" "; // 최소 번호  
		}
		
} 
