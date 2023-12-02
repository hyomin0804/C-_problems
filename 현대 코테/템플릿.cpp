#include <bits/stdc++.h>
using namespace std;

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

void dfs(int here){
    visited[here] = 1; 
    for(int there : adj[here]){
        if(visited[there]) continue;
        dfs(there);
    }
}

void dfs(int y, int x){
	visited[y][x]=1;

	for(int i=0; i<4; i++){
		ny= y+ dy[i];
		nx= x+ dx[i]; 
		
		
		if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
		if(mp[ny][nx]==0) continue;
		if(visited[ny][nx]) continue;
		dfs(ny,nx); 
		
	}
}

void bfs(int here){
	visited[here] = 1; 
	
    queue<int> q; 
    q.push(here);
    
    while(q.size()){
        int here = q.front(); q.pop();
        
        for(int there : adj[here]){
            if(visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
 }
 
void bfs(int sy, int sx){ 
    visited[sy][sx] = 1;
    
    queue<pair<int, int>> q; 
    q.push({sy, sx});  
    
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue; 
            if(visited[ny][nx]) continue; 
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx}); 
        } 
    }
} 

int main(){
	
	
	return 0;
} 
