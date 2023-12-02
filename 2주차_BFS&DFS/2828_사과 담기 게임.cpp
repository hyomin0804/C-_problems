/*
// 내가 작성한 코드  
#include <bits/stdc++.h>
using namespace std;

int n,m,a,J, cnt;
vector<int> blank; // 바구니  

int main(){
	
	cin >> n >> m;
	cin >> J; 
	
	int app[J]; //사과 배열  
	
	for(int i=0; i<J; i++){
		cin >> a;
		app[i]=a-1; // 인덱스 0으로 맞추기 위해 -1 
	}
	
	for(int i=0; i<m; i++){
		blank.push_back(i); // 바구니 설정 그림 참고  
	}
	
	for( int i: app){
		if( i <= blank.back() && i >= blank.front()){
			//cout << "바구니 안움직임\n"; 
			continue;
			
		}else if( i > blank.back() ){
			int a= i- blank.back();
			//cout << "바구니 오른쪽으로 " << a << "만큼 이동\n"; 
			cnt+=a;
			for( int j=0; j<m; j++ ){
				blank[j]+= a;
				
				continue; 
			}
		}else if ( i < blank.front() ) {
			int b= blank.front() -i ;
			//cout << "바구니 왼쪽으로 " << b << "만큼 이동\n";
			cnt+=b; 
			for( int j=0; j<m; j++ ){
				blank[j]-= b;
				
				continue; 
			}
		}
		
	}
	cout << cnt << "\n";
	
	
	
	return 0;
} 
*/

// 정답 코드 참고 시
#include <bits/stdc++.h>
using namespace std;
int n,m,J,a,l,r,ret;

int main () {
	cin>> n >> m >> J;
	int app[J];
	
	for(int i=0; i<J; i++){
		cin >> a; 
		app[i]=a-1;
	}
	
	l= 0;
	
	for(int a: app){
		r= l+m-1;
		
		if( a >= l && a<=r) continue;
		else if( a > r){
			ret+=a-r;
			l+= a-r;
			
		}else if( a < l ){
			ret+=l-a;
			l-= l-a ;

		}
	}
	cout << ret;
	return 0;
	
} 
