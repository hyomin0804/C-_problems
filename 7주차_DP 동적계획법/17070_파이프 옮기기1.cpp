#include <bits/stdc++.h>
using namespace std;
int mp[17][17]; // 1���� �����ϹǷ� 16�� �ƴ� 17�� �ؾ���!!! 
int dp[17][17][3]; // x,y,direction
int n;
 // �� ������ ������ ������ ���� ���� ������  
 
bool check(int y, int x, int d){
	if(d==0 || d==2){ // ���γ� ���� 
 		if(!mp[y][x]) return true; // �������� ���� �� �ִٸ� 
 		
	}else if( d==1 ){ //�밢������ ���������� Ȯ��  
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
	
	dp[1][2][0]=1; // �� �κп� ������ �ִٴ� �� ǥ��  
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<n+1; j++){
			// ���η� �ִ� ��� �� �� �ִ� ����� �� 2��  
			if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][0]; // ������ �� ĭ  
			if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][0]; // �밢�� �Ʒ��� �� ĭ 
			
			// ���η� �� �� �ִ� ����� �� 2��  
			if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][2]; // �밢�� �Ʒ��� �� ĭ  
			if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][2]; //�Ʒ��� �� ĭ  
			
			// �밢������ �� �� �ִ� ����� ��  
			if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][1]; 
			if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][1];
			if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][1]; // �밢�� �Ʒ��� �� ĭ  
			
		}
		
	}
	int ret = dp[n][n][0]+dp[n][n][1]+dp[n][n][2] ;
	cout << ret;
	return 0;
} 
