#include <bits/stdc++.h>
using namespace std;
const int INF=987564321;
int n;
char mp[20][20];
string s;
int a[44], ret=INF;
// �ุ �������� ���� �����ش� ������ �ִ�. 
void go(int here){
	//�� �� ������ �� ���� üũ  
	if( here ==n +1){
		int sum=0;
		for(int i=1; i<= (1 << (n-1)); i*=2){ //i�� 1��° H(1)H(2)T(4) 
			int cnt=0;
			for(int j=1; j<=n; j++) if(a[j] & i) cnt++;
			sum += min(cnt,n-cnt); 
		} 
		ret =min(ret,sum);
		return;
	} 
	go(here+1); // ���� �ȵ����� 
	a[here]=~a[here]; // ������ 
	go(here +1); 
}
int main (){
	cin >> n;
	for (int i=1; i<=n; i++){
			cin >> s;
			int value=1;
			for(int j=0; j<s.size(); j++){
				if(s[j]=='T') a[i] |= value; // "T"�� ��������  �� �����ڷ� ��Ʈ ����ŷ , �迭 ��ü�� �ϳ��� ���ڷ� ��ȯ  
				value *=2;
			
		}
	}
	
	go(1); // 1���� �����ؼ�  
	cout << ret << "\n";
	return 0;
}
	
