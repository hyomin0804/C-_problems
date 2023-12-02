#include <bits/stdc++.h>
using namespace std;

int mp[10][10],visited[10][10];
int dy[]={-1, 0, 1, 0};
int dx[]={0,1,0,-1};
int n,ret,cnt=1,x,y;
string s;

vector<int> ret_;

int main() {
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			mp[i][j] = s[j]-'0';
		}
	}
	
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < n; j++){
			cout << mp[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	return 0;
}

/*
ют╥б  
6
011000 
011011
000011
000011
110010
111000
*/

