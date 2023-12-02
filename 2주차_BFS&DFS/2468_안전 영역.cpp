#include <bits/stdc++.h>
using namespace std;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n,ret=-1,max_;
int mp[100][100],mmpp[100][100],visited[100][100];

void dfs(int y, int x){
	visited[y][x]=1;
	
	for(int i=0; i<4; i++){
		int ny= y+ dy[i];
		int nx= x+ dx[i];
		
		if(nx >=n || nx<0 || ny>=n || ny<0 || mmpp[ny][nx]) continue;
		if( visited[ny][nx] ) continue;
		dfs(ny, nx);
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mp[i][j];
			max_=max(max_, mp[i][j]); // ���� �ִ� ����  
		}
	}
	
	for(int k=0; k<=max_; k++){ // ���� ���̴� 0- max_���� ����  
		int cnt=0; // �� ���� ���� ���� ������ ���� ����  
		memset(visited,0,sizeof(visited)); // �� ���� �޶����� ���� �ʱ�ȭ  
		memset(mmpp,0,sizeof(mmpp)); 
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
			if(k>=mp[i][j]) mmpp[i][j]=1; // ��� ���� mmpp�� 1�� ǥ��  
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(mmpp[i][j] || visited[i][j]) continue;
				cnt++;
				dfs(i,j);
			}
		}
		
		ret=max(ret, cnt);
	}
	
	cout << ret << "\n";
	
	
	return 0;
	
} 
