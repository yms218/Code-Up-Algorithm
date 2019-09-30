#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
// 시간복잡도 : Elog(V) -> Mlog(N)
#define Pair pair<int, int>
#define MAX 1001
vector<Pair> v[MAX];
int dist[MAX];
int N, M;

void dijkstra(int start, int end){
    bool visited[MAX] = {0,};
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;
    dist[start] = 0; 
    pq.push({0, start});
    while(!pq.empty()) {
        int cur;
        do {
            cur = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[cur]); 
        if(visited[cur]) break;
        visited[cur] = true;
        for(int i = 0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int d = v[cur][i].second;
            if(dist[next] > dist[cur] + d){
                dist[next] = dist[cur] + d;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    cout << dist[end] << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }
    int st, en;
    cin >> st >> en;
    for(int i = 1; i<=N; i++) dist[i] = INT_MAX;
    dijkstra(st, en);
    return 0;
}