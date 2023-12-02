#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n,m,x,y,ret=-987654321;
string s;
char mp[20][20];
int visited[20][20];
int alpa[26];

int dfs(int y, int x, char c){

	alpa[c-'A']=1;
	
	for(int i=0; i<4; i++){
		
		int ny= y+ dy[i];
		int nx= x+ dx[i];

		if(nx>=m || nx<0 || ny >=n || ny<0 ) continue;
		if(visited[ny][nx]) continue;
		if(alpa[mp[ny][nx]-'A']) continue;
		
		visited[ny][nx]=visited[y][x]+1;
		dfs(ny, nx,mp[ny][nx]);
		alpa[mp[ny][nx]-'A']=0;
		ret = max(ret, visited[ny][nx]);
		
	}

	return ret;
	
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n;i++){
		cin >> s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
		}
	}
	cout << "\n";
	
	visited[0][0]=1;
	
	cout << dfs(0,0,mp[0][0]);
	cout << "\n";
	for(int i=0; i<n;i++){
		for(int j=0;j<m;j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
} 

/*
#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n,m,x,y;
string s;
char mp[20][20];
int visited[20][20];
int alpa[26];

int bfs(int sy, int sx, char c){
    int ret=-987654321;
	visited[sy][sx]=1;
	alpa[c-'A']=1;

	queue<pair<int,int>> q;
	q.push({sy,sx});
	
	while(q.size()){
		tie(y,x)=q.front(); q.pop();
		
		for(int i=0; i<4; i++){
			int ny= y+ dy[i];
			int nx= x+ dx[i];

			if(nx>m || nx<0 || ny >n || ny<0 ) continue;
			if(visited[ny][nx]) continue;
			if(alpa[mp[ny][nx]-'A']) continue; 
			alpa[mp[ny][nx]-'A']=1;
			visited[ny][nx]=visited[y][x]+1;
			q.push({ny,nx});
			ret=max(ret, visited[ny][nx]);
		}
		
		
	}
	return ret;
	
	
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n;i++){
		cin >> s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
		}
	}
	cout << "\n";

	cout << bfs(0,0,mp[0][0]);
	
	cout << "\n";
	for(int i=0; i<n;i++){
		for(int j=0;j<m;j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
} 
*/
