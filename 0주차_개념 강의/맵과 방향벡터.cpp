#include <bits/stdc++.h>
using namespace std;

const int V=3;
int mp[V][V], nx, ny;
bool visited[V][V];

const int dy[]={-1, 0, 1, 0};
const int dx[]={0, 1, 0, -1};

void go(int y, int x){
	visited[y][x]=1;
	cout << y << " : " << x << '\n';
	for(int i=0; i<4; i++){
		ny= y+ dy[i];
		nx= x+ dx[i]; 
		
		// 범위 제한, 언더플로우, 오버플로우 방지 
		if (ny<0 || ny>=V || nx<0 || nx>=V) continue;  // 가장 먼저 쓰기 
		if(mp[ny][nx]==0) continue;
		if(visited[ny][nx]) continue;
		
		if(mp[ny][nx]==1) go(ny,nx); // 그냥 go(ny,nx);해도 됨  
		
	}
}

int  main(){

	for (int i =0; i<3; i++){
		for (int j =0; j<3; j++){
			cin >> mp[i][j];
			
		}
	}
	
	go(0,0);
		
	return 0; 
}
