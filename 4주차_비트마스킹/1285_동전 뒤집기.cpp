#include <bits/stdc++.h>
using namespace std;
const int INF=987564321;
int n;
string s;
int a[20], ret=INF; //a: i번째 행에 있는 동전의 상태를 나타내는 변수
// 행만 뒤집으면 열의 최적해는 정해져 있다. 
void go(int here){
	//행 다 뒤집고 열 조건 체크  
	if( here ==n ){
		int sum=0;
		for(int i=1; i<= (1 << (n-1)); i*=2){ //i는 1번째 H(1)H(2)T(4) 
			int cnt=0;
			for(int j=1; j<=n; j++) if(a[j] & i) cnt++; //i 번째 열에서 T 개수 cnt로 체크  
			sum += min(cnt,n-cnt); //  열 안뒤집었을때 t개수  vs  열 뒤집었을때 t개수 (n-cnt) 비교해서 더 큰 수 
			
		} 
		ret =min(ret,sum); //뒷면이 위를 향하여 놓일 수 있는 동전의 최소 개수를 출력한다. 
		return;
	} 
	
	go(here+1); // 동전 안뒤집고 
	
	a[here]=~a[here]; // 뒤집어서  
	go(here +1); //  뒤집은 걸로 go  
}
int main (){
	cin >> n;
	for (int i=1; i<=n; i++){
			cin >> s;
			int value=1; 
			for(int j=0; j<s.size(); j++){
				if(s[j]=='T') a[i] |= value; // a[i]에서 value 번째 비트 켜기  
				value *=2; // 1 2 4 8 16 ...으로 각 비트 자리수에 함연산 하기 위함  
				//s[j]가 'T'일 때, value가 2라면 a[i]의 두 번째 비트가 1로 설정
		}
	}
	
	go(1); // 1부터 시작해서  
	cout << ret << "\n";
	return 0;
}

