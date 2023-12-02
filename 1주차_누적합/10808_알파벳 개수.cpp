#include <bits/stdc++.h>
using namespace std;
string s;
int alph[26];

int main(){
	cin >> s;
	for(char a: s){
		alph[a-'a']+=1;
	}
	for(int i: alph){
		cout << i << " ";
	}
	
	return 0;
} 
