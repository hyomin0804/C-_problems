#include <bits/stdc++.h>
using namespace std;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
int n,m,x,y,ret=0,mx=0;
int visited[50][50];
vector<int> v;
char mp[50][50];
string s;

void bfs(int sy, int sx){
	visited[sy][sx]=1;
	queue<pair<int,int>> q;
	q.push({sy,sx});
	
	while(q.size()){
		tie(y,x)=q.front(); q.pop();
		
		for(int i=0; i<4; i++){
			int nx= x+dx[i];
			int ny= y+dy[i];
			
			if(nx>=m || nx<0 || ny>=n || ny<0 || mp[ny][nx]=='W') continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx]=visited[y][x]+1;
			q.push({ny,nx});
			mx=max(mx, visited[ny][nx]);
		}
	}
	return;
}

		
int main(){
	cin >> n >> m;
	
	for (int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<s.size();j++){
			mp[i][j]=s[j];
		}
	}
	
	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mp[i][j]=='W' ) continue; // 여기서는 || visited[i][j] 하면 안됨. 이건 dfs에서 
			
			memset(visited, 0, sizeof(visited));
			bfs(i,j);
		}
	}

	cout << mx-1 ;
	return 0;
} 
