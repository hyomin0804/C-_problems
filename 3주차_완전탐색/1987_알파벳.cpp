#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n,m,x,y;
string s;
char mp[20][20];
int alpa[26];
int ret=-1;

void go(int y, int x, int cnt){
	ret=max(ret, cnt);
	
	for(int i=0; i<4; i++){
		
		int ny= y+ dy[i];
		int nx= x+ dx[i];

		if(nx>=m || nx<0 || ny >=n || ny<0 ) continue;
		if(alpa[mp[ny][nx]-'A']) continue;

		alpa[(int)mp[ny][nx]-'A']=1;
		go(ny, nx, cnt+1);
		alpa[mp[ny][nx]-'A']=0;
		
	}
	return;
	
} 

int main(){
	cin >> n >> m;
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i=0; i<n;i++){
		cin >> s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
		}
	}
	
	alpa[mp[0][0]-'A']=1;
	go(0,0,1); // 출발점도 포함한다 했으니 cnt=1부터 시작  
	
	cout <<ret << "\n";
	
	return 0;
} 
