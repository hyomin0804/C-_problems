#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a, ret=1e18;

//���� ������ mid ���� �������� ������ �л��鿡�� �����־��� ��, 
//���� ���� ������ ���� �л��� ���� ���� n ���������� �Ǵ��ϴ� ��
//���� ���� ������ ī����  
bool check(ll mid){ 
	ll num=0; // �׷� ũ��  
	for(int i=0; i<m; i++){ //�������� �׷� � ����������� ǥ��  
		num+=a[i]/mid; // mid ������ ������ ��,  ������ �� �׷� ��  
		if(a[i]%mid) num++;// ������ ������ �߰� +1 
	}
	return n>=num; // �л����� �׻� �׷������ Ŀ����. �׷��� ������ �� ����  
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	
	cin >>n >>m;
	ll lo=1, hi=0, mid; // �������� �ּ�=1 ���� ����  
	vector<int> v;
	for(int i=0; i<m; i++){
		cin >> a;
		v[i].push_back(a);
		hi=max(hi, a[i]) // ���� �� ���� ������ ���� ��  
	}
	while(lo<=hi){
		mid=(lo+hi)/2; // �� mid ������ �л��鿡�� ������  
		
		if (check(mid)){ // �ش� �ּڰ����� ������ ���ִ��� �˻�  
			ret=min(ret,mid))// ������ �ּ� ã��  
			hi=mid-1;
		} else lo=mid+1
	}
	
	cout << ret << "\n";	
	
	return 0;
} 
