#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int N, M;
int ans;
char A[51][51];
const int dr[] = {0,1,0,-1};
const int dc[] = {1,0,-1,0};
int BFS(int r, int c){
    int cnt = -1;
    queue<pair<int, int> > q;
    bool visited[51][51] = {false,};
    q.push(make_pair(r, c));
    visited[r][c] = true;
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--){
            int now_r = q.front().first;
            int now_c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nr = now_r + dr[i];
                int nc = now_c + dc[i];
                if(nr < 0 || nc < 0 || nr >= N || nc >=M) continue;
                if(visited[nr][nc]) continue;
                if(A[nr][nc] == 'W') continue;
                visited[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
        cnt++;
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> A[i][j];
        }
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(A[i][j] == 'L'){
                ans = max(BFS(i,j), ans);
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}