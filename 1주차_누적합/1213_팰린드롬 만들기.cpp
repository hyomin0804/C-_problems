/*
// 내 코드 -> map 이용 
#include <bits/stdc++.h>
using namespace std;
string s,ret;
map<char,int> mp; 
char mid;
int flag;

int main(){
	cin >> s;
	for(char a: s){
		mp[a]++;
		
	}
	vector<pair<char, int>> sorted_chars(mp.begin(), mp.end());
	sort(sorted_chars.begin(), sorted_chars.end(), greater<pair<char,int>>());
	
	for(auto i : sorted_chars){
		if(i.second %2 ==0){
			for(int a=0; a<i.second; a+=2){
				ret+=i.first;
				ret=i.first+ret;
			}
			
		}else{
			flag++;
			if(flag>=2){
				cout << "I'm Sorry Hansoo\n";
				return 0;
			} 
			for(int a=0; a<i.second-1; a+=2){
				ret+=i.first;
				ret=i.first+ret;
			}
			mid=i.first;
		}
	
	}
	if(mid) {
		ret= ret.substr(0, ret.size()/2) + mid + ret.substr(ret.size()/2);
		//ret.insert(ret.begin() + ret.size() / 2, mid);
	}
	cout << ret;
	return 0;
} 
*/

//정답 코드 -> 배열 이용  

#include<bits/stdc++.h> 
using namespace std; 
string s, ret; 
int cnt[200], flag; 
char mid;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for(char a : s)cnt[a]++;
	for(int i = 'Z'; i >= 'A'; i--){
		if(cnt[i]){
			if(cnt[i] & 1){
				mid = i;flag++;
				cnt[i]--;
			}
			if(flag == 2)break;
			for(int j = 0; j < cnt[i]; j += 2){
				ret = char(i) + ret; 
				ret += char(i);
			}
		}
	}
	if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
	if(flag == 2)cout << "I'm Sorry Hansoo\n";
	else cout << ret << "\n"; 
	
	return 0; 
}
