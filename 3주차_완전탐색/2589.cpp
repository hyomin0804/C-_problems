#include <bits/stdc++.h>
using namespace std;
char mp[51][51];
int visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n,m,nx,ny;
int mx=-1;

void bfs(int y, int x){
	memset(visited,0,sizeof(visited));
	queue<pair<int,int>> q;
	visited[y][x]=1;
	q.push({y,x});
	
	while(q.size()){
		tie(y,x) = q.front(); q.pop();
		
		for(int i=0; i<4; i++){
			
			nx= x + dx[i];
			ny = y + dy[i];
			
			if (nx <0 || ny <0 || nx>=m || ny>=n) continue;
			if(mp[ny][nx]=='W') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx]=visited[y][x]+1;
			q.push({nx,ny});
			mx=max(mx, visited[ny][nx]);
			
			cout << "\n";
			for (int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << visited[n][m] << " ";
			}
			cout << "\n";
			}
			cout << "\n";
		
			}
	}
	
	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << visited[n][m] << " ";
		}
	cout << "\n";
	}
	
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %c",&mp[i][j]);
			
		}
	}

	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mp[i][j] == 'L'){
			bfs(i,j);
		}
	}
	}
	cout<<mx-1<<"\n";
	return 0;	
} 
