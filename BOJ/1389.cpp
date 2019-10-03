#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define MAX 101
#define INF 5000
#define Pair pair<int, int>
int dist[MAX];
int user[MAX];
int N, M;
vector<Pair> v[MAX];
int dijkstra(int start){
    for(int i = 1; i<=N; i++) dist[i] = INF;
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;
    bool visited[MAX] = {false,};
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
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
    int sum = 0;
    for(int i = 1; i<=N; i++) sum += dist[i];
    user[start] = sum;
    return sum;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(make_pair(b, 1));
        v[b].push_back(make_pair(a, 1));
    }    
    int ans = INF;
    for(int i = 1; i<=N; i++){
        ans = min(ans, dijkstra(i));
    }
    int i;
    for(i = 1; i<=N; i++){
        if(user[i] == ans) break;
    }
    cout << i << "\n";
    return 0;
}