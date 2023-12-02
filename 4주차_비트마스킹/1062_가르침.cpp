#include <bits/stdc++.h>
using namespace std;
int n,k;
string s,ss;
vector<string> v;
int words[51]; //�ܾ� -> ��Ʈ�� ��Ÿ��, �ܾ� �ִ� 50��  

 
int count(int mask){ // ��� �ܾ �������  
	int cnt=0;
	for(int word : words){
		if(word && (word & mask)==word) cnt ++;
	}
	return cnt;
} 

int go(int index, int k, int mask){
	if(k<0) return 0; //��� �� �ִ� k �پ�  
	if(index==26) return count(mask); // 26���� ��� �� �ִ°� �� üũ  
	
	int ret=go(index+1, k-1, mask | (1<<index)); // index�� ���ĺ��� ���� ��  
	// �ش� �κ��� �ƴҶ��� ���ĺ��� �ȹ�� �� �ִ�.  
	if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
		ret= max(ret, go(index+1,k,mask)); // �̰� �ȹ�﷡  
	}
	return ret;
}

int main(){
	cin >> n >> k; 
	
	for(int i=0; i<n; i++){
		cin >> s;
		for(char a: s){
			words[i] |= (1<<(a-'a')); // �Է� ���� ��Ʈ �ѱ� 
			
		}
	}
	cout << go(0,k,0) << "\n"; // idx: �� ����� , k�� ��� �� ����, ��� �ܾ�   
	
	return 0;
} 
