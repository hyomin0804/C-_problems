#include <bits/stdc++.h>
using namespace std;

int cnt[26]; //���� ���� ���� �� �ڵ����� 0���� �ʱ�ȭ �� 
string str;

int main(){
	cin >> str;

	for(char a : str){
		cnt[a-'a']++;
	}
	for (int i=0; i<26; i++) cout << cnt[i] << " ";
	return 0; 
} 
