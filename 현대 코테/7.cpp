#include <bits/stdc++.h>
using namespace std;
int n,a;
string mp[100][100];
string temp1,temp2;

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

static void r_turn(int y, int x) {							// �ð�������� ��ĭ�� ���� �ű�� 
						
		int tmp = arr[y][x];						// �ӽ������� ���� 1��
		int d = 0;									// ����迭�� index
		
		while(true) {	
			
			int ny= y+ dy[1];
			int nx= x+ dx[1];		
			
			if(ny==0 && nx==0) {					// �ѹ��� ��������
				arr[ny][nx] = tmp;				// �ӽ������� ���Ҹ� now�� �Է��� �������´�
				break;
			}
			
			if(check(nx, ny) && visit[nx][ny]==0) {	// ������ ������� �̵� 
				arr[ny][nowj] = arr[ny][nx];		// ���� �̵� 
				nowi = ny; nowj = nj;
				visit[ni][nj] = 1;
			}else {
				d = (d+1)%4;						// ���� �ٲٱ� 
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
	if(a>0){ // �ð� ȸ��  
		flag=0;
		
	}else{ // �ݽð� ȸ��  
		flag=1;
		
	}
	
	
	
	return 0;
} 
