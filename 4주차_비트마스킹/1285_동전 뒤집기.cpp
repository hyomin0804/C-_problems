#include <bits/stdc++.h>
using namespace std;
const int INF=987564321;
int n;
string s;
int a[20], ret=INF; //a: i��° �࿡ �ִ� ������ ���¸� ��Ÿ���� ����
// �ุ �������� ���� �����ش� ������ �ִ�. 
void go(int here){
	//�� �� ������ �� ���� üũ  
	if( here ==n ){
		int sum=0;
		for(int i=1; i<= (1 << (n-1)); i*=2){ //i�� 1��° H(1)H(2)T(4) 
			int cnt=0;
			for(int j=1; j<=n; j++) if(a[j] & i) cnt++; //i ��° ������ T ���� cnt�� üũ  
			sum += min(cnt,n-cnt); //  �� �ȵ��������� t����  vs  �� ���������� t���� (n-cnt) ���ؼ� �� ū �� 
			
		} 
		ret =min(ret,sum); //�޸��� ���� ���Ͽ� ���� �� �ִ� ������ �ּ� ������ ����Ѵ�. 
		return;
	} 
	
	go(here+1); // ���� �ȵ����� 
	
	a[here]=~a[here]; // �����  
	go(here +1); //  ������ �ɷ� go  
}
int main (){
	cin >> n;
	for (int i=1; i<=n; i++){
			cin >> s;
			int value=1; 
			for(int j=0; j<s.size(); j++){
				if(s[j]=='T') a[i] |= value; // a[i]���� value ��° ��Ʈ �ѱ�  
				value *=2; // 1 2 4 8 16 ...���� �� ��Ʈ �ڸ����� �Կ��� �ϱ� ����  
				//s[j]�� 'T'�� ��, value�� 2��� a[i]�� �� ��° ��Ʈ�� 1�� ����
		}
	}
	
	go(1); // 1���� �����ؼ�  
	cout << ret << "\n";
	return 0;
}

