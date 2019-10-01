#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
// 시간복잡도 Elog(N) -> 200000 * log(800);
// 1->a->b->N 혹은 1->b->a->N 두 경로 중 하나이고 중간에 없으면 종료한다.
#define MAX 801
#define Pair pair<int, int>
vector<Pair> v[MAX];
int ans = INT_MAX;
int N, E;
int dist[MAX];
bool flag;

void dijkstra(int start, int end){
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
}

void solve(int x, int y){
    int sum = 0;
    dijkstra(1, x);
    if(dist[x] == INT_MAX) return;
    sum += dist[x];
    dijkstra(x, y);
    if(dist[y] == INT_MAX) return;
    sum += dist[y];
    dijkstra(y, N);
    if(dist[N] == INT_MAX) return;
    sum += dist[N];
    ans = min(ans, sum);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> E;
    for(int i = 0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    int v1, v2;
    cin >> v1 >> v2;
    solve(v1, v2);
    solve(v2, v1);
    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";
    return 0;
}
