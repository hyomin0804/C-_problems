#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int ret, ny, nx, a, b;
bool visited[104][104]; 
int mp[104][104]; // 맵의 최대 범위 100에 충분히 104까지 


void dfs(int y, int x){
	visited[y][x]=1;
	cout << y << " : "<< x << '\n';
	 
	for (int i=0; i<4; i++){
		
		ny= y+ dy[i];
		nx= x+ dx[i];
		
		if (ny>=a || nx>=b || ny<0 || nx<0) continue;
		if (mp[ny][nx]==0) continue;
		if(visited[ny][nx]) continue;
		
		if (mp[ny][nx]==1 && visited[ny][nx]==0) dfs(ny,nx);
		
		}
	return;
}

int main(){ 

    cin >> a >> b; 
    for(int i = 0; i < a; i++){
    	for(int j = 0; j < b; j++){
    		cin >> mp[i][j];
		}
	}
	for(int i = 0; i < a; i++){
    	for(int j = 0; j < b; j++){
    		if(mp[i][j] == 1 && visited[i][j]==0){
    			cout << i<< " : " << j << " 에서 dfs 탐색이 일어납니다.\n"; 
    			ret++; dfs(i, j);
			} 
		}
	}
	cout << ret << '\n'; 
    return 0;
}


/*
5 5
1 0 1 0 1
1 1 0 0 1
0 0 0 1 1
0 0 0 1 1
0 1 0 0 0
*/
