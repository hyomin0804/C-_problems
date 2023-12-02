#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
int n, m;
int px,py, cx,cy ,nx,ny;
int mp[104][104];
int dy[]={-1, 0, 1, 0};
int dx[]={0,  1, 0, -1};
int visited[104][104];

void bfs(int y, int x){
	visited[y][x]=1;
	q.push({y,x});

	while(q.size()){
    	tie(y, x) = q.front(); q.pop(); 

		for (int i=0; i<4; i++){
			ny= y+ dy[i];
			nx= x+ dx[i];
			
			if(mp[ny][nx]==0) continue;
			if(nx<0 || ny<0 || nx>=m || ny >= n) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1; 
			q.push({ny,nx});
			
			}
		for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		cout << visited[i][j] << ' '; 
        	}
        	cout << '\n';
   		 } 
		cout << '\n';
		cout << '\n';
		} 
		
		
	
	}


int main(){
	cin >> n >> m;
	cin >> py >> px;
	cin >> cy >> cx;
	
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> mp[i][j];
		}
	}
	cout << '\n';
	cout << '\n';
	bfs(py,px);
	
	
	cout << visited[cy][cx] << "\n";  
    // 최단거리 디버깅 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	cout << visited[i][j] << ' '; 
        }
        cout << '\n';
    } 
    return 0;
} 

/*
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
*/
