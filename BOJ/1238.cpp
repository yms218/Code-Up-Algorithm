#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define MAX 1001
#define Pair pair<int, int>
vector<Pair> v[MAX];
int N, M, X;
int dist[MAX];

int dijkstra(int start, int end){
    for(int i = 1; i<=N; i++) dist[i] = INT_MAX;
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
    return dist[end];
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> X;
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        // 단방향
        v[a].push_back(make_pair(b,c));
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        if(i == X) continue;
        int temp = dijkstra(i, X) + dijkstra(X, i);
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}

