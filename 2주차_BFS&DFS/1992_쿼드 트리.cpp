#include <bits/stdc++.h>
using namespace std;
int mp[101][101];
string s;
int n;
string quard(int y, int x, int size){
	
	if(size==1) return string(1, mp[y][x]); //char를 string으로 만들어주는 함수 , 문자열 길이 1 
	char b= mp[y][x]; //일단 아무거나 뽑기 확인해야하니까 
	string ret="";

	for(int i=y; i<size+y; i++){
		for(int j=x; j<size+x; j++){
			if (mp[i][j] != b){
				ret += "(";
				
				// 순서 중요!! 
				ret += quard(y,x,size/2); //왼쪽  위 
				ret += quard(y,x+size/2,size/2); // 오른쪽 위  
				ret += quard(y+size/2,x,size/2); // 왼쪽 아래  
				ret += quard(y+size/2,x+size/2,size/2);	// 오른쪽 아래
								
				ret += ")";
				return ret;
			}
			
		}
	}
	return string(1, mp[y][x]);
	

}

int main(){
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> s;
		for(int j=0; j<n ;j++){
			mp[i][j] = s[j];
		}
	}
	
	cout << quard(0,0,n) << "\n";// 시작점 x,y 배열 크기  
	
	return 0;
}
