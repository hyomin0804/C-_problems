#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n,m,x,y;
string s;
char mp[20][20];
int ret=-1;

void go(int y, int x, int num, int cnt){
	ret=max(ret, cnt);
	
	for(int i=0; i<4; i++){
		
		int ny= y+ dy[i];
		int nx= x+ dx[i];

		if(nx>=m || nx<0 || ny >=n || ny<0 ) continue;
		
		int next= (1<< (mp[ny][nx]-'A'));
		if((num & next)==0) go(ny,nx,num | next,cnt+1); // ���ϱ�   
		// ���ĺ� �湮 ���� �˻�  
		// ABC ��� �� ���� C�� �� ������ 1+2+4 & 4 ���� 1�� ���ͼ� ����  
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
	
	go(0,0, 1 << (mp[0][0]-'A') ,1); // ������� �����Ѵ� ������ cnt=1���� ����  
	
	cout <<ret << "\n";
	
	return 0;
}
