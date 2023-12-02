#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
int mp[104][104];
int visited[104][104];

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

int m,n,x,y,nx,ny;

int main(){
	cin >> n >> m;
	//ÀÔ·Â µû´Úµû´ÚÀº scanf
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%1d", &mp[i][j]);
		}
	}
	visited[0][0]=1;
	q.push({0,0});
	
	while(q.size()){
		tie(y,x) = q.front(); q.pop();
		
		for (int i=0; i<4; i++){
			ny= y + dy[i];
			nx= x + dx[i];
			
			if (nx>m || ny > n || ny<0 || nx<0 ) continue;
			if(visited[ny][nx]) continue;
			if (mp[ny][nx]==0) continue;
			
			visited[ny][nx]=visited[y][x] +1;
			q.push({ny,nx});
		}
		
	}
	
	cout << visited[n-1][m-1] << '\n';
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout <<visited[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
	
}
