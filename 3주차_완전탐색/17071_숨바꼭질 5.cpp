#include <bits/stdc++.h>
using namespace std;
const int max_n = 500000; 
int visited[2][max_n + 4]; // 수빈이의 홀짝과 동생 위치  
int a, b, ok, turn = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    if(a == b){cout << 0 << "\n"; return 0;}
    
    queue<int> q;
    visited[0][a] = 1; //수빈이가 방문 했는지 안했는지 체크  
    q.push(a);
    while(q.size()){
        b += turn;
        if(b > max_n)break;  
        if(visited[turn % 2][b]) { // 짝수일때 동생위치에 수빈이가 미리 방문을 했다면  
            ok = true;
            break;
        }
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            int x = q.front(); q.pop();
			for(int nx : {x + 1, x - 1, x * 2}){
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1; 
                if(nx == b){
                    ok = 1; break;
                }
                q.push(nx); 
			} 
			if(ok)break;
        }
        if(ok)break;
        turn++;
    }
    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}

