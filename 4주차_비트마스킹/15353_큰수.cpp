#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
string a,b;
int minn,carry;
string ret,big;

int main(){
	cin >> a >> b;
	
	while (a.size() || b.size() || carry){
		int sum=0;
		if(a.size()){
			sum+= a.back() -'0';
			a.pop_back();
		}
		
		if(b.size()){
			sum+= b.back() -'0';
			b.pop_back();
		}
		if(carry) {
			sum+=1;
			carry=0;
		}
		
		if(sum>=10){
			ret+= (sum%10)+ '0';
			carry=1;
		}else{
			ret+=sum +'0';
		}
		
	}
	reverse(ret.begin(), ret.end());
	cout << ret;
	return 0;
}
