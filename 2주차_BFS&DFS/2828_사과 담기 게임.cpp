/*
// ���� �ۼ��� �ڵ�  
#include <bits/stdc++.h>
using namespace std;

int n,m,a,J, cnt;
vector<int> blank; // �ٱ���  

int main(){
	
	cin >> n >> m;
	cin >> J; 
	
	int app[J]; //��� �迭  
	
	for(int i=0; i<J; i++){
		cin >> a;
		app[i]=a-1; // �ε��� 0���� ���߱� ���� -1 
	}
	
	for(int i=0; i<m; i++){
		blank.push_back(i); // �ٱ��� ���� �׸� ����  
	}
	
	for( int i: app){
		if( i <= blank.back() && i >= blank.front()){
			//cout << "�ٱ��� �ȿ�����\n"; 
			continue;
			
		}else if( i > blank.back() ){
			int a= i- blank.back();
			//cout << "�ٱ��� ���������� " << a << "��ŭ �̵�\n"; 
			cnt+=a;
			for( int j=0; j<m; j++ ){
				blank[j]+= a;
				
				continue; 
			}
		}else if ( i < blank.front() ) {
			int b= blank.front() -i ;
			//cout << "�ٱ��� �������� " << b << "��ŭ �̵�\n";
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

// ���� �ڵ� ���� ��
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
