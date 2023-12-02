#include <bits/stdc++.h>
using namespace std;
int n,k;
string s,ss;
vector<string> v;
int words[51]; //단어 -> 비트로 나타냄, 단어 최대 50개  

 
int count(int mask){ // 배운 단어를 기반으로  
	int cnt=0;
	for(int word : words){
		if(word && (word & mask)==word) cnt ++;
	}
	return cnt;
} 

int go(int index, int k, int mask){
	if(k<0) return 0; //배울 수 있는 k 다씀  
	if(index==26) return count(mask); // 26까지 배울 수 있는거 다 체크  
	
	int ret=go(index+1, k-1, mask | (1<<index)); // index의 알파벳을 배우는 중  
	// 해당 부분이 아닐때만 알파벳을 안배울 수 있다.  
	if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
		ret= max(ret, go(index+1,k,mask)); // 이거 안배울래  
	}
	return ret;
}

int main(){
	cin >> n >> k; 
	
	for(int i=0; i<n; i++){
		cin >> s;
		for(char a: s){
			words[i] |= (1<<(a-'a')); // 입력 받은 비트 켜기 
			
		}
	}
	cout << go(0,k,0) << "\n"; // idx: 뭘 배울지 , k번 배울 수 있음, 배운 단어   
	
	return 0;
} 
