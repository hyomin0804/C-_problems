#include <bits/stdc++.h>
using namespace std;
int mp[101][101];
string s;
int n;
string quard(int y, int x, int size){
	
	if(size==1) return string(1, mp[y][x]); //char�� string���� ������ִ� �Լ� , ���ڿ� ���� 1 
	char b= mp[y][x]; //�ϴ� �ƹ��ų� �̱� Ȯ���ؾ��ϴϱ� 
	string ret="";

	for(int i=y; i<size+y; i++){
		for(int j=x; j<size+x; j++){
			if (mp[i][j] != b){
				ret += "(";
				
				// ���� �߿�!! 
				ret += quard(y,x,size/2); //����  �� 
				ret += quard(y,x+size/2,size/2); // ������ ��  
				ret += quard(y+size/2,x,size/2); // ���� �Ʒ�  
				ret += quard(y+size/2,x+size/2,size/2);	// ������ �Ʒ�
								
				ret += ")";
				return ret;
			}
			
		}
	}
	return string(1, mp[y][x]);
	

}

int main(){
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> s;
		for(int j=0; j<n ;j++){
			mp[i][j] = s[j];
		}
	}
	
	cout << quard(0,0,n) << "\n";// ������ x,y �迭 ũ��  
	
	return 0;
}
