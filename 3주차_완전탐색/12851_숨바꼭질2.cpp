#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000; 
int visited[MAX+4];
int cnt[MAX+4];

int main() {
    int n, m;
    cin >> n >> m;
    if(n == m){
        puts("0"); puts("1");
        return 0; 
    } 
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    
    while (q.size()) {
        int now = q.front(); q.pop();
        
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next <= MAX) { 
                if (!visited[next]) {
                    q.push(next); 
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                } else if (visited[next] == visited[now] + 1) { // 방문표시 되어있어도 최단거리라면  
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    
    cout << visited[m] - 1 << '\n'; // 시간은 -1 
    cout << cnt[m] << '\n';
    return 0;
}
