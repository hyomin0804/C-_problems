//영역 구하기  
#include <bits/stdc++.h>
using namespace std;

int mp[10][10],visited[10][10];
int dy[]={-1, 0, 1, 0};
int dx[]={0,1,0,-1};
int n,ret,cnt=1,x,y;
vector<int> ret_;

int dfs(int y, int x){
	
	ret+=1;
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		
		if(nx>n || nx <0 || ny>n || ny <0 || mp[ny][nx]==0) continue;
		if(visited[ny][nx]) continue;
		visited[ny][nx]=visited[y][x]+1;
		dfs(ny,nx);

	}
	return ret;
}

int main() {
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mp[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			
			if(mp[i][j]==1 && visited[i][j]==0){
				ret=0;
				cnt++;
				visited[i][j]=1;
				int a= dfs(i,j);
				ret_.push_back(a);
			}
				
		}
	}
	cout << "\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << visited[i][j] << " ";
			}
			cout << "\n";
		}
	
	sort(ret_.begin(), ret_.end());
	
	cout << cnt << "\n";
	for(int i: ret_) cout << i << " ";
	
	return 0;
}
/*
6
0 1 1 0 0 0
0 1 1 0 1 1
0 0 0 0 1 1
0 0 0 0 1 1
1 1 0 0 1 0
1 1 1 0 0 0

4
4 5 7

////////////////

4
1 0 0 0
1 0 0 0
0 0 0 0
0 0 1 1

2
2 2
*/

