/*
#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,cnt;
char mp[301][301],visited[301][301];
string ss;

int dy[]={-1, 0, 1, 0};
int dx[]={0,1,0,-1};
vector<int> e;
vector<int> s;
int a,b,c,d;

int main(){
	
	cin >> n >> m;
	cin >> a >> b >> c >>d;
	a--;b--;c--;d--;
	for(int i=0; i<n; i++){
		cin >> ss;
		for(int j=0; j<m; j++){
			mp[i][j]=ss[j];
		}
	}
	
	
	visited[a][b]=1;
	queue<pair<int,int>> q;
	q.push({a,b});
	cnt=0;
	
	while (mp[c][d] != '0'){ // ��ǥ ������ 0���� ����Ⱑ ��ǥ  
		cnt++;
		queue<pair<int,int>> temp;
		
		while (q.size()){
			tie(y,x)=q.front(); q.pop();

			for(int i=0; i<4; i++){
				int ny= y +dy[i];
				int nx= x +dx[i];
				if(nx <0 || nx >=m || ny<0 || ny>=n || visited[ny][nx]) continue;
				visited[ny][nx]=cnt;
				
				if(mp[ny][nx]!='0') {
					mp[ny][nx]=='0';
					temp.push({ny,nx}); // �� ���� �湮 ����  
				}else{ // 0�� ��  
					q.push({ny,nx});
				}

			}
		}
		q=temp; // temp�� ������ �������� �ٽ� start! 
		
	}

	cout << visited[c][d] << "\n";
	return 0;
}
*/
#include <bits/stdc++.h>

using namespace std; 
char a[301][301];
int n, m, x1, y1, x2, y2; 
typedef pair<int, int> pii;
int visited[301][301];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ret,e,b,c,d; 
string ss;
queue<pair<int,int>> q;

int main(){
    cin >> n >> m;
	cin >> e >> b >> c >>d;
	e--;b--;c--;d--;
	for(int i=0; i<n; i++){
		cin >> ss;
		for(int j=0; j<m; j++){
			a[i][j]=ss[j];
		}
	}
   
    q.push({e,b});
    visited[e][b] = 1; 
    int cnt = 0; 
    
    while(a[c][d] != '0'){ 
        cnt++;
        queue<pair<int,int>> temp; 
        
        while(q.size()){
        	int x;
			int y;
            tie(y,x) = q.front(); q.pop();
            
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i]; 
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 
                visited[ny][nx] = cnt;  
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0'; 
                    temp.push({ny,nx});
                }
                else q.push({ny,nx}); 
            }
        }
        q = temp;  
    }
    cout << visited[c][d] << "\n";
}
