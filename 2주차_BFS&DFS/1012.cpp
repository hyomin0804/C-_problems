#include <bits/stdc++.h>
using namespace std;
int mp[54][54], visited[54][54];
int T,n,m,cnt,a,b,ret,ny,nx;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

void dfs(int y, int x){
	visited[y][x]=1;
	
	for (int i=0; i<4; i++){
		ny= y + dy[i];
		nx= x + dx[i];
		
		if( nx<0 || ny<0 || nx >=m || ny >= n || mp[ny][nx]==0) continue;
		if(visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	
	return;
}

int main(){
	cin >> T;
	while (T--){
		//ÃÊ±âÈ­ 
		fill(&mp[0][0], &mp[54][54], 0);
		fill(&visited[0][0], &visited[54][54], 0);
		ret=0;
		cin >> n >> m >> cnt;
	
		for (int i=0; i<cnt; i++){
			cin >> a >> b;
			mp[a][b]=1;
		}
		
		for (int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(mp[i][j]==1 && visited[i][j]==0){
					dfs(i,j);
					ret++;
				}
			}
		}
		cout << ret << "\n";

	}
	return 0;
}


