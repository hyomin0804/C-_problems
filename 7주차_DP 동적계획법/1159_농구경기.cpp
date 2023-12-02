//counting star~는 맵또는 배열~ 

//내가 작성한 코드- map으로 작성  
#include <bits/stdc++.h>
using namespace std;
int n,flag;
map<char,int> mp;
string s;


int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		
		cin>> s;
		auto k=mp.find(s[0]);
		
		if(k !=mp.end()){
			mp[s[0]]++;
		}else mp.insert({s[0],1});
	}
	for(auto i: mp){
		if(i.second>=5){
			cout << i.first;
			flag=1;
		}
		
	}
	if(flag !=1 ) cout<< "PREDAJA";

	return 0;

//정답 코드-배열로 푼 코드  
#include <bits/stdc++.h>
using namespace std;
int cnt [26]; // 알파벳은 항상 26개!  
string s, ret;
int n;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		
		cin>> s;
		cnt[s[0]-'a']++; // 0-26으로 좌표 이동 
		}
	
	for(int i=0; i<26; i++){
		if(cnt[i]>=5) ret += i+'a'; // char(i+"a") c++은 유연해서 가능  
		}
	
	if(ret.size()) cout<< ret;
	else cout<< "PREDAJA";
	return 0;
} 
