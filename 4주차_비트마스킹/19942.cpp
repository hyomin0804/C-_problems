#include <bits/stdc++.h>
using namespace std;
const int INF=987654231;
int n,mp,mf,ms,mv;
int b,c,d,e,ret=INF, sum; 
struct A{ 
	int mp, mf, ms, mv, cost;
}a[16]; // struct ������ 16�� ���� �� �ִ� �迭 ���� 
 map<int, vector<vector<int>>> ret_v; // key, value <����, ��ᱸ��>  

 int main(){
 	cin >> n;
 	cin >> mp >> mf >> ms >> mv;
 	// ��Ʈ ����ŷ 
 	for (int i=0; i<n; i++){
 		cin >> a[i].mp >> a[i].mf >> a[i].ms>> a[i].mv>> a[i].cost;
 }
 	for (int i=1; i< (1<<n); i++){ //2��n����, ��� ����� ���� ���� 00,01,10,11 ...
		b=c=d=e=sum=0; 
		vector<int> v;
		
		for(int j=0; j<n; j++){ // ����� ����, ��� ���  Ž��  
			if(i&(1<<j)){ // ����� ����, ��Ʈ�� 1���� �Ǵ� //01�� 1, 10�� 2. 11�� {1,2} 
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
		cout << ret << "\n"; // �ּ� ��� 
		for(int a: ret_v[ret][0]){
			cout << a <<" "; // �ּ� ��ȣ  
		}
		
	}
	

 }
 
 /*
 ��� ����� ���� ã�� �Ʒ��� �ڵ忡�� i=0�� �ƴ� 1���� �����ϴ� ������ ����Ḧ �ƹ��͵� ���� �ʴ� ����� ���� ���� �����ΰ���?(�ּ� 1�� �̻� ����Ḧ ���� �ϱ� �����ΰ���?)

for (int i=1; i< (1<<n); i++)*/
