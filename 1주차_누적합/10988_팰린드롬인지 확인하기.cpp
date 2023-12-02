#include <bits/stdc++.h>
using namespace std;

 // 내가 작성한 코드 
string str;
vector<char> a,b;

int main(){
	cin >> str;
	for(char i : str){
		a.push_back(i);
		b.push_back(i);
	}
	reverse(a.begin(), a.end());
	if (a==b) cout << 1 ;
	else cout << 0;


	return 0;
} 

//답안
string s, temp;
int main(){
	cin >> s;
	temp=s;
	reverse(temp.begin(), temp.end());
	if(temp==s) cout << 1;
	else cout << 0;
	return 0;
} 
