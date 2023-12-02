#include <bits/stdc++.h>
using namespace std;
int mp[17][17]; // 1부터 시작하므로 16이 아닌 17로 해야함!!! 
int dp[17][17][3]; // x,y,direction
int n;
 // 이 문제는 파이프 오른쪽 끝만 봐도 무방함  
 
bool check(int y, int x, int d){
	if(d==0 || d==2){ // 가로나 세로 
 		if(!mp[y][x]) return true; // 파이프를 놓을 수 있다면 
 		
	}else if( d==1 ){ //대각선으로 내려갔을때 확인  
	 	if(mp[y][x]==0 && mp[y-1][x]==0 && mp[y][x-1]==0){
	 		return true;
		 }
	 } 
	 
	return false;
 }
int main(){
	
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> mp[i][j];
		}
	}
	
	dp[1][2][0]=1; // 이 부분에 파이프 있다는 것 표기  
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<n+1; j++){
			// 가로로 있는 경우 갈 수 있는 경우의 수 2개  
			if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][0]; // 옆으로 한 칸  
			if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][0]; // 대각선 아래로 한 칸 
			
			// 세로로 갈 수 있는 경우의 수 2개  
			if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][2]; // 대각선 아래로 한 칸  
			if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][2]; //아래로 한 칸  
			
			// 대각선으로 갈 수 있는 경우의 수  
			if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][1]; 
			if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][1];
			if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][1]; // 대각선 아래로 한 칸  
			
		}
		
	}
	int ret = dp[n][n][0]+dp[n][n][1]+dp[n][n][2] ;
	cout << ret;
	return 0;
} 
