//counting star~�� �ʶǴ� �迭~ 

//���� �ۼ��� �ڵ�- map���� �ۼ�  
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

//���� �ڵ�-�迭�� Ǭ �ڵ�  
#include <bits/stdc++.h>
using namespace std;
int cnt [26]; // ���ĺ��� �׻� 26��!  
string s, ret;
int n;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		
		cin>> s;
		cnt[s[0]-'a']++; // 0-26���� ��ǥ �̵� 
		}
	
	for(int i=0; i<26; i++){
		if(cnt[i]>=5) ret += i+'a'; // char(i+"a") c++�� �����ؼ� ����  
		}
	
	if(ret.size()) cout<< ret;
	else cout<< "PREDAJA";
	return 0;
} 
