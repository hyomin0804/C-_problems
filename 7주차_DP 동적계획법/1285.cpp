#include <bits/stdc++.h>
using namespace std;
const int INF=987564321;
int n;
char mp[20][20];
string s;
int a[44], ret=INF;
// 행만 뒤집으면 열의 최적해는 정해져 있다. 
void go(int here){
	//행 다 뒤집고 열 조건 체크  
	if( here ==n +1){
		int sum=0;
		for(int i=1; i<= (1 << (n-1)); i*=2){ //i는 1번째 H(1)H(2)T(4) 
			int cnt=0;
			for(int j=1; j<=n; j++) if(a[j] & i) cnt++;
			sum += min(cnt,n-cnt); 
		} 
		ret =min(ret,sum);
		return;
	} 
	go(here+1); // 동전 안뒤집고 
	a[here]=~a[here]; // 뒤집고 
	go(here +1); 
}
int main (){
	cin >> n;
	for (int i=1; i<=n; i++){
			cin >> s;
			int value=1;
			for(int j=0; j<s.size(); j++){
				if(s[j]=='T') a[i] |= value; // "T"를 기준으로  함 연산자로 비트 마스킹 , 배열 자체를 하나의 숫자로 변환  
				value *=2;
			
		}
	}
	
	go(1); // 1부터 시작해서  
	cout << ret << "\n";
	return 0;
}
	
