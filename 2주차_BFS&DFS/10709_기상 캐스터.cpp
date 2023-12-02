#include <bits/stdc++.h>
using namespace std;
int h,w;
int mp[100][100];
char s;
bool flag;

int main(){
	memset(mp, -1, sizeof(mp));
	
	cin >> h >> w;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> s;
			if (s=='c') mp[i][j]=0;
		}
	}
	
	for(int i=0; i<h; i++){
		flag=0;
		for(int j=0; j<w; j++){
			if (mp[i][j]==0 && flag==0){
				flag=1;
			}else if(mp[i][j]==0 && flag!=0){
				continue;
			}else if(mp[i][j]==-1 && flag==1) mp[i][j]=mp[i][j-1]+1;
			
		}
	}
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout << mp[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
} 
