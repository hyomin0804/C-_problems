/*
//���� ó�� § �ڵ�-> �켱���� ť �̿�-> ������ ū�ż����� -9,-3,-1�ϸ� �ּҷ� �����ϴ� Ƚ���� �ƴ�-> �ݷ� ���� 
#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,a1,a2,a3,b1,b2,b3;
priority_queue<int> pq;

int main(){
	
	cin >> n;
	
	for (int i=0; i<n; i++){
		cin >> k;
		pq.push(k);
	}
	
	while(pq.size()){
		cnt++;
		if(pq.size()>=3){
			a1=pq.top(); pq.pop();
			b1=a1-9; 
			a2=pq.top(); pq.pop();
			b2=a2-3;
			a3=pq.top(); pq.pop();
			b3=a3-1;
			
			if(b1>0) pq.push(b1);
			if(b2>0) pq.push(b2);
			if(b3>0) pq.push(b3);
		}else if(pq.size()==2){
			a1=pq.top(); pq.pop();
			b1=a1-9; 
			a2=pq.top(); pq.pop();
			b2=a2-3;

			if(b1>0) pq.push(b1);
			if(b2>0) pq.push(b2);

		}else if(pq.size()==1){
			a1=pq.top(); pq.pop();
			b1=a1-9; 
			if(b1>0) pq.push(b1);

		}
		
	}
		
	cout << cnt;	
	
} 
*/




// ���� ��� �ٽ� § �ڵ� -> bfs 
#include <bits/stdc++.h>
using namespace std;
int n;
int scv[3]; // scv �ִ� 3��  
int visited[64][64][64]; // ���� Ƚ��(�湮 �Ÿ�) ����� 

int _a[6][3]={
	{9,3,1},
	{9,1,3},
	{3,1,9},
	{3,9,1},
	{1,3,9},
	{1,9,3}
};

// 3�� �̻��� struct�� �����ϱ�  
struct A{
	int a,b,c;
};

int bfs(int a, int b, int c){
	visited[a][b][c]=1;
	queue<A> q;
	q.push({a,b,c});
	
	while(q.size()){
		if(visited[0][0][0]) break; // ���� 0,0,0 ������ �湮�ߴٸ� �׸�  
		
		int a = q.front().a; 
		int b = q.front().b; 
		int c = q.front().c; 
		q.pop();
		
		
		for(int i=0; i<6; i++){
			int na= max(0,a -_a[i][0] ); // ������ �Ǹ� visited�� �ε����� ���� ����  
			int nb= max(0,b -_a[i][1] );
			int nc= max(0,c -_a[i][2] );
			
			if(visited[na][nb][nc]) continue;
			visited[na][nb][nc]=visited[a][b][c]+1;
			q.push({na,nb,nc});
		}
		
		
	}
	
	return visited[0][0][0] -1; 

}

int main (){
	cin >> n;
	
	for (int i=0; i<n; i++){
		cin >> scv[i];
	}
	
	cout << bfs(scv[0],scv[1],scv[2] ) << "\n";
	return 0;
} 
