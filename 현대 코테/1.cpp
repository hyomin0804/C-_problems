#include <bits/stdc++.h>
using namespace std;
string s,s_;
int n,a,b,c,d;
vector<string> p;
vector<string> boat;
vector<vector<string>> noo;

void combi(int start, vector<int> b){
// ���� ���� (�߿�)
	if(b.size() == n){
		print(b); // ���� ����
		return;
	}
	
	for(int i = start + 1; i < n; i++){
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; //���� ũ�� 
	cin >> a;// �ǳʾ��ϴ� ��� 
	for(int i=0; i<a; i++){
		cin >> s;
		p.push_back(s);
	}
	cin >> b; // �踦 �� �� �ִ� ���
	for(int i=0; i<b; i++){
		cin >> s_;
		boat.push_back(s_);
	}
	// ���Ͽ� �������� �ȵǴ� ���� �� 
	cin >> c; 
	for(int i=0; i<c; i++){
		cin >> d;
		for(int i=0; i<d; i++){
			cin >> k_;
			noo[i].push_back(k_);
		}
	}
	
	
	combi(-1,p);
	
	

	return 0;
} 


	getline(cin, s);
	while(true){
		auto a= s.find(" ");
		if(a!=string::npos){
			cnt++;
			s.erase(0, a);
			cout  << s <<"\n";
		}else break;
	}
	
	cout << cnt;
