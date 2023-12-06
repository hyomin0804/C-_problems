#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,cnt;
char mp[5][5];
int visited[5][5];
string s;


int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

int dfs(int y, int x){

	if(y == 0 && x == m - 1){
		if(k == visited[y][x]){
			return 1;
		}
		return 0; 
	}

	int ret=0;
	for(int i=0; i< 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny<0 || nx <0 || ny>=n || nx >=m || visited[ny][nx]) continue;
		if(mp[ny][nx]=='T') continue;
		visited[ny][nx]=visited[y][x]+1;
		ret+=dfs(ny,nx);
		visited[ny][nx]=0;

	}
	return ret;
}


int main(){
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++){
		cin >> s; 
		for(int j = 0; j < m; j++){
			mp[i][j] = s[j];
		}
	} 
	visited[n-1][0]=1;
	cout << dfs(n-1,0);

	return 0;
} 
