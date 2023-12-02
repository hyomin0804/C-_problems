#include <bits/stdc++.h>
using namespace std;
int n,a;
string mp[100][100];
string temp1,temp2;

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

static void r_turn(int y, int x) {							// 시계방향으로 한칸씩 원소 옮기기 
						
		int tmp = arr[y][x];						// 임시저장할 원소 1개
		int d = 0;									// 방향배열의 index
		
		while(true) {	
			
			int ny= y+ dy[1];
			int nx= x+ dx[1];		
			
			if(ny==0 && nx==0) {					// 한바퀴 돌았을때
				arr[ny][nx] = tmp;				// 임시저장한 원소를 now에 입력후 빠져나온다
				break;
			}
			
			if(check(nx, ny) && visit[nx][ny]==0) {	// 달팽이 모양으로 이동 
				arr[ny][nowj] = arr[ny][nx];		// 원소 이동 
				nowi = ny; nowj = nj;
				visit[ni][nj] = 1;
			}else {
				d = (d+1)%4;						// 방향 바꾸기 
			}
		}
	}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int i=0; i<n; i++){
			cin >> mp[i][j];
		}
	}
	 
	cin >> a;
	if(a>0){ // 시계 회전  
		flag=0;
		
	}else{ // 반시계 회전  
		flag=1;
		
	}
	
	
	
	return 0;
} 
