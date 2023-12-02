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
		
		// ���� ����, ����÷ο�, �����÷ο� ���� 
		if (ny<0 || ny>=V || nx<0 || nx>=V) continue;  // ���� ���� ���� 
		if(mp[ny][nx]==0) continue;
		if(visited[ny][nx]) continue;
		
		if(mp[ny][nx]==1) go(ny,nx); // �׳� go(ny,nx);�ص� ��  
		
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
