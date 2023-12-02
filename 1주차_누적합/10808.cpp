#include <bits/stdc++.h>
using namespace std;

int cnt[26]; //전역 변수 선언 시 자동으로 0으로 초기화 됨 
string str;

int main(){
	cin >> str;

	for(char a : str){
		cnt[a-'a']++;
	}
	for (int i=0; i<26; i++) cout << cnt[i] << " ";
	return 0; 
} 
