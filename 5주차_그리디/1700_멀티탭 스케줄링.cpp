#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int k,n,a[104], multi[104],cnt;
const int INF=987654321;
vector<int> v; //��Ƽ�ǿ� ����ִ� �ڵ��  

int main(){
	cin >> k >> n;
	for(int i=0; i<n; i++) cin >> a[i]; // �̷� ���� ��ġ  
	
	for(int i=0; i<n; i++){ // ���ڿ�ǰ ��� �������  
		if(!multi[a[i]]){ // ��Ƽ�ǿ� ���������� ��� �ƴϸ� if��  
		  
			if(v.size()==k){ // ��Ƽ���� �� á�ٸ�  
				// ����ȭ  
				int last_idx=0; // ���� �� �̷� �����Ǵ� �ε���  
				int pos;
				for(int _a:v){ //��Ƽ�ǿ� ����ִ� �ڵ��  
					int here_pick=INF;
					for(int j=i+1; j<n; j++){ // ���� �� �̷��� ������ ģ�� Ȯ��  
						if(_a==a[j]){
							here_pick =j;
							break;
						}
					}
					if(last_idx < here_pick){ // ���� �� �̷��� �����Ǵ� ��ǰ ����  
						last_idx = here_pick;
						pos=_a; // ����Ī �� �ڵ�  
					}
				} 
				multi[pos]=0; // ��Ƽ�ǿ��� �̱�  
				cnt++;
				v.erase(find(v.begin(),v.end(), pos)); // ��Ƽ�ǿ��� �̱�  
			} 
			// ��Ƽ���� �� �� �ִٸ� ��� push 
			v.push_back(a[i]);
			multi[a[i]]=1; // ��Ƽ�� �Ⱦ����� ǥ��  
		}
	}	
	
	cout << cnt << "\n";
	return 0;
} 
