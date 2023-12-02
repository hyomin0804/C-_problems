#include <bits/stdc++.h>
using namespace std;
int sum, dist_,n,m,d, mid=1;
int ret=0;
int result= 987654321;

int mp[51][51];
vector<pair<int,int>> chicken;
vector<pair<int,int>> home;
vector<vector<int>> chickenList;

void combi(int start, vector<int> idx){

	if(idx.size() == m){
		chickenList.push_back(idx);
		return;
	}
	
	for(int i = start + 1; i < chicken.size(); i++){
		idx.push_back(i);
		combi(i, idx);
		idx.pop_back();
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mp[i][j];
			if(mp[i][j]==2) chicken.push_back({i,j});
			if(mp[i][j]==1) home.push_back({i,j});
			
		}
	}
	 
	vector<int> idx;
	combi(-1, idx);
	
	for (vector<int> li : chickenList){
		ret=0;
		for (pair<int,int> home_: home){
			int min_=987564321;
			for(int i: li ){
				int dist= abs(home_.first-chicken[i].first)+abs(home_.second-chicken[i].second);
				 min_=min(dist,min_); // 여기 부분 변수 명 조심, 업데이트 해야함 
			}
			ret+=min_;
		}
		result=min(ret, result);
	}
		
		
	cout << result;

	return 0;
	
} 
