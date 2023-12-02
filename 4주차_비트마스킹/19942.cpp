#include <bits/stdc++.h>
using namespace std;
const int INF=987654231;
int n,mp,mf,ms,mv;
int b,c,d,e,ret=INF, sum; 
struct A{ 
	int mp, mf, ms, mv, cost;
}a[16]; // struct 구조를 16개 담을 수 있는 배열 선언 
 map<int, vector<vector<int>>> ret_v; // key, value <가격, 재료구성>  

 int main(){
 	cin >> n;
 	cin >> mp >> mf >> ms >> mv;
 	// 비트 마스킹 
 	for (int i=0; i<n; i++){
 		cin >> a[i].mp >> a[i].mf >> a[i].ms>> a[i].mv>> a[i].cost;
 }
 	for (int i=1; i< (1<<n); i++){ //2의n제곱, 모든 경우의 수에 대해 00,01,10,11 ...
		b=c=d=e=sum=0; 
		vector<int> v;
		
		for(int j=0; j<n; j++){ // 식재료 개수, 모든 재료  탐색  
			if(i&(1<<j)){ // 식재료 고르기, 비트가 1인지 판단 //01은 1, 10은 2. 11은 {1,2} 
				v.push_back(j+1);
				b+=a[j].mp; 
				c+=a[j].mf;
				d+=a[j].ms;
				e+=a[j].mv;
				sum+=a[j].cost;
				
			}
		}
		if(b>=mp && c>=mf && d>=ms && e>=mv){
			if(ret>=sum){
				ret=sum;
				ret_v[ret].push_back(v);
			}
		}
 		 	
	}
	
	if(ret ==INF) cout << -1 << "\n" ;
	else{
		sort(ret_v[ret].begin(), ret_v[ret].end());
		cout << ret << "\n"; // 최소 비용 
		for(int a: ret_v[ret][0]){
			cout << a <<" "; // 최소 번호  
		}
		
	}
	

 }
 
 /*
 모든 경우의 수를 찾는 아래의 코드에서 i=0이 아닌 1부터 시작하는 이유는 식재료를 아무것도 고르지 않는 경우의 수는 없기 때문인가요?(최소 1개 이상 식재료를 골라야 하기 때문인가요?)

for (int i=1; i< (1<<n); i++)*/
