#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
	int n =100; // ���� ��ȯ �� ����
	int b = 16; // 2�������� �ٲٱ�
	while(n>1){
		v.push_back(n%b);
		n/=b;
	} 
	if(n==1)v.push_back(1);
	reverse(v.begin(), v.end()); // ������ �ؿ��� ���� �����ؾ��ؼ� 
	for (int a:v){
		if(a>=10) cout << char(a+55); //if(a>=10) �̰� 8���� ���� 16���� ��ȯ�� ���� �ʿ��� 
		else cout<<a;
	}
} 
