#include <bits/stdc++.h>
using namespace std;
int mp[101][101], visited[101][101];
int n,ny,nx;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
int fin=1;

void dfs(int y, int x, int depth){
	visited[y][x]=1;
	for(int i=0; i<4; i++){
		ny = y + dy[i];
		nx = x + dx[i];
		if(nx<0 || ny<0 || nx>=n || ny >=n ) continue;
		if (!visited[ny][nx] && mp[ny][nx]>depth) dfs(ny,nx,depth);
		}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> mp[i][j];
		}
	}
	
	for (int depth=1; depth<101; depth++){
		int ret=0;
		fill(&visited[0][0],&visited[101][101],0);
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if(mp[i][j]>depth && !visited[i][j]){
					dfs(i,j,depth);
					ret++;
					cout << ret << "\n";
			
				}
			}
		}
		fin=max(fin, ret);
	}
	
	
	cout << fin << '\n';
	return 0;
}
