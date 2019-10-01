#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define MAX 20000
#define Pair pair<int, int>
vector<Pair> v[MAX];
char A[101][102];
int B[101][101];
int N, M;
int dist[MAX];

void dijkstra(int start){
    for(int i = 1; i<=N*M; i++) dist[i] = INT_MAX;
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;
    bool visited[MAX] = {0,};
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int cur;
        do{
            cur = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[cur]);
        if(visited[cur]) break;
        visited[cur] = true;
        for(int i = 0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int d = v[cur][i].second;
            if(dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
    cin >> M >> N;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> A[i][j];
            B[i][j] = cnt++;
        }
    }
    // 가로 처리
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M-1; j++){
            v[B[i][j]].push_back(make_pair(B[i][j + 1], A[i][j + 1] - 48));
            v[B[i][j + 1]].push_back(make_pair(B[i][j], A[i][j] - 48));
        }
    }
    // 세로 처리
    for(int i = 1; i<=M; i++){
        for(int j = 1; j<=N-1; j++){
            v[B[j][i]].push_back(make_pair(B[j + 1][i], A[j + 1][i] - 48));
            v[B[j + 1][i]].push_back(make_pair(B[j][i], A[j][i] - 48));
        }
    }
   
    dijkstra(1);

    cout << dist[N * M] << "\n";
    return 0;
}
