#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>

using namespace std;
int a,r,c,t,mp[55][55],ret,temp[55][55];
vector<pair<int,int>> v1,v2;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int dy1[]={0,-1,0,1};
int dx1[]={1,0,-1,0};

int dy2[]={0,1,0,-1};
int dx2[]={1,0,-1,0};

vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]){   
    vector<pair<int, int>> v; 
    int cnt = 0; 
    int y = sy; 
    int x = sx;
    while(true){ 
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];  
        if(ny == sy && nx == sx)break;
        if(ny < 1 || ny >= r+1 || nx < 1 || nx >= c+1){
            cnt++; 
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        } 
        if(ny == sy && nx == sx)break;
        y = ny; x = nx; 
        v.push_back({ny, nx});
    }
    return v;
}

void spread(){
	memset(temp,0,sizeof(temp));
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++ ){
			if(mp[i][j]!=0 && mp[i][j]!=-1 ){
				int tempp=mp[i][j]/5;
				for(int k=0; k<4; k++){
					int ny= i+dy[k];
					int nx= j+dx[k];
					
					if(ny<1 || nx<1 || nx>=c+1 || ny>=r+1 || mp[ny][nx]==-1) continue;
					temp[ny][nx]+=tempp;
					mp[i][j]-=tempp;
					
				}
			}
		}
	}
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++ ){
			mp[i][j]+=temp[i][j];
		}
	}
	return;
}
// 회전 알고리즘  
void wind(vector<pair<int,int>> &v) { // 이거 & 빼보기  
	
    for(int i=v.size()-1; i>0;i--){
    	mp[v[i].first][v[i].second]=mp[v[i-1].first][v[i-1].second];
	}
    mp[v[0].first][v[0].second]=0;
    return; 
}

int main(){
	cin >> r >> c >> t;
	bool flag=1;
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			cin >> a;
			mp[i][j]=a;
		 if(a==-1){
			if(flag){
				v1=chung(i,j,dy1,dx1); // 미리 바람에 날릴 장소 담아놓기  
				flag=0;
			}else{
				v2=chung(i,j,dy2,dx2);
			}
				
			}
		}
	}
	while (t--){
		spread();
		wind(v1);
		wind(v2);
	}
	
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++ ){
			if(mp[i][j]!=-1){
				ret+=mp[i][j];
			}
		}
	}
	
	cout << ret << "\n";
	
	return 0;
} 
