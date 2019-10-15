#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
#include <climits>
using namespace std;
#define MAX 10
vector<pair<pair<int, int>, int> > v;
int ans = INT_MAX;
int N, M;
bool some[100];
int A[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX + 1][MAX + 1];
const int dr[] = {0,1,0,-1};
const int dc[] = {1,0,-1,0};
int div() {
    int city = 0;
    queue<pair<int, int> > q;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            // 방문하지 않은 섬이라면
            if(A[i][j] && !visited[i][j]){
                ++city;
                q.push(make_pair(i, j));
                visited[i][j] = city;
                while(!q.empty()) {
                    int now_r = q.front().first;
                    int now_c = q.front().second;
                    q.pop();
                    for(int k = 0; k<4; k++){
                        int nr = now_r + dr[k];
                        int nc = now_c + dc[k];
                        if(nr < 0 || nc < 0 || nr >= N || nc >=M) continue;
                        if(A[nr][nc] && !visited[nr][nc]){
                            visited[nr][nc] = city;
                            q.push(make_pair(nr, nc));
                        }
                    }
                } 
            }       
        }
    }
    return city;
}

void get_dist(int city){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(visited[i][j] == city){
                // 다른 섬과 거리를 구함
                for(int k = 0; k<4; k++){
                    for(int l = 1; l<=9; l++){
                        int nr = i + l * dr[k];
                        int nc = j + l * dc[k];
                        if(nr < 0 || nc < 0 || nr >= N || nc >= M) break;
                        if(visited[nr][nc] == city) break;
                        // 다른 섬을 만난 경우
                        if(visited[nr][nc] > 0){
                            int next = visited[nr][nc];
                            // 다리 길이가 2이상
                            if(l <= 2) break;
                            // 섬->섬이 처음인 경우
                            if(dist[city][next] == INT_MAX && dist[next][city] == INT_MAX){
                                dist[city][next] = l - 1;
                            }
                            else{
                                // 최단길이로 갱신
                                if(dist[city][next] == INT_MAX){
                                    dist[next][city] = min(dist[next][city], l-1);
                                }
                                else{
                                    dist[city][next] = min(dist[city][next], l-1);
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

bool isConnected(int city){
    queue<int> q;
    bool tmp[MAX + 1] = {false,};
    bool chk[MAX + 1][MAX + 1] = {false,};
    for(int i = 0; i<v.size(); i++){
        if(some[i]){
            chk[v[i].first.first][v[i].first.second] = true;
            chk[v[i].first.second][v[i].first.first] = true;
        }
    }
    q.push(1);
    tmp[1] = true;
    int cnt = 1;
    while(!q.empty() ) {
        int now = q.front(); q.pop();
        for(int i = 1; i<=city; i++){
            if(!tmp[i] && chk[now][i]){
                tmp[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    if(cnt == city) return true;
    return false;

}

void DFS(int cnt, int now, int sel){
    if(cnt == sel){
        if(isConnected(sel + 1)){
            int sum = 0;
            for(int i = 0; i<v.size(); i++){
                if(some[i]){
                    sum += v[i].second;
                }
            }
            ans = min(ans, sum);
        }
        return;
    }
    for(int i = now; i<v.size(); i++){
        if(!some[i]){
            some[i] = true;
            DFS(cnt + 1, i + 1, sel);
            some[i] = false;
        }
    }
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
    // 섬을 나눠주고 섬의 개수를 리턴
    int city = div();
    // 섬과 섬 사이거리 무한대로 초기화
    for(int i = 1; i<=city; i++){
        for(int j = 1; j<=city; j++){
            dist[i][j] = INT_MAX;
        }
    }
    // 섬과 섬사이의 최단거리를 구함
    for(int i = 1; i<=city; i++){
        get_dist(i);
    }
   
    for(int i = 1; i<=city; i++){
        for(int j = 1; j<=city; j++){
            if(dist[i][j] != INT_MAX){
                v.push_back(make_pair(make_pair(i,j),dist[i][j]));
            }
        }
    }
    DFS(0, 0, city - 1);
    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";
    return 0;
}