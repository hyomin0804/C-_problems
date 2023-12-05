// ���������� �ð� �ʰ� dfs �ΰ� -> bfs queue �ΰ��� Ǯ�����  
#include <bits/stdc++.h>
using namespace std;
int r,c,cnt;
string s;
bool flag;
vector<pair<int,int>> v;
pair<int,int> s1, s2;
char mp[1504][1504];
int visited[1504][1504];
int visited2[1504][1504];

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

void dfs(int y, int x){
	
	// ���� ���� ���Ϳ� ���  
	if(mp[y][x]=='X'){
		v.push_back({y,x});
		return;
	}
	
	visited[y][x]=1;
	
	for(int i=0; i<4; i++){
		
		int ny= y+ dy[i];
		int nx= x + dx[i];
		
		if(ny>=r || nx>=c || ny<0 || nx<0 ) continue;
		if(visited[ny][nx]) continue;
		dfs(ny, nx);
		
	}
	return;
}

void check(int y, int x){
	
	visited2[y][x]=1;

	for(int i=0; i<4; i++){
		
		int ny= y+ dy[i];
		int nx= x + dx[i];
		
		if(ny>=r || nx>=c || ny<0 || nx<0 || mp[y][x]=='X' ) continue;
		if(visited2[ny][nx]) continue;
		check(ny, nx);
		
	}
	return;
	
	
} 

int main(){
	cin >> r >> c;
	for(int i=0; i<r; i++){
		cin >>s;
		for(int j=0; j<c; j++){
			mp[i][j]=s[j];
			
			if(s[j]=='L' &&flag==0){
				s1={i,j};
				flag=1;
			}else if(s[j]=='L' &&flag==1){
				s2={i,j};
			}
		}
	}
	
	while (true){
		// ������ ������ �ִ��� üũ  
		check(s1.first,s1.second);
		if(visited2[s2.first][s2.second]==1) break;
	
		//�ʱ�ȭ  
		memset(visited, 0, sizeof(visited));
		memset(visited2, 0, sizeof(visited2));
		v.clear();
		
		// ���� ���� Ž��  
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(mp[i][j]!='X' && visited[i][j]==0){
					
					dfs(i,j);
				}
				
			}
		}
		
		// ���� ���̱�  
		for(auto a: v){
			mp[a.first][a.second]='.';
		}
		// �Ϸ� ���ϱ�  
		cnt++; 
		
		
	}
	
	cout << cnt << "\n";
	
	return 0;
}
