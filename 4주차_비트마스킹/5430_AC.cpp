#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int t,a;
string s,ss;

int main(){
	cin >> t; //�׽�Ʈ ���̽�  
	while(t--){
		//flag=error, flagg=reverse ���� 
		bool flag=0,flagg=0;
		
		cin >> s; // ���� �Լ� RDD
		cin >> a; // ���� ����  
		
		deque<int> dq;
		cin >> ss;
		
		string aa="";
		for(char d: ss){
		
			if(isdigit(d)){
				aa+=d;
			}else{
				if(aa.size()){
					int cc=atoi(aa.c_str());
					dq.push_back(cc);
					aa="";
				}
			}

		}


		for(char a: s){
			
			if(a=='R'){
				flagg = !flagg;
		
			}else if(a=='D'){
				if(dq.size()){
					if(flagg==0) dq.pop_front();
					else dq.pop_back();
					
				}else{
					flag=1;
					break;
				}
			}
		}
		
		if(flag==1) cout << "error\n";
		else{
			
			if(flagg==1){
				reverse(dq.begin(),dq.end());
			}
			cout << "[";
			for(int i=0; i<dq.size();i++){
				cout << dq[i];
				if(i<dq.size()-1) cout << ",";
			}
			cout << "]\n";
		}
		
		
	}
	
	return 0;
}
