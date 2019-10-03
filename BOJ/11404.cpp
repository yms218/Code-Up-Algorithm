#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;
#define MAX 101
#define Pair pair<int, int>
int N, M;
int dist[MAX];
vector<Pair> v[MAX];
void dijkstra(int start){
    for(int i = 1; i<=N; i++) dist[i] = INT_MAX;
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
    for(int i = 1; i<=N; i++){
        dijkstra(i);
        for(int j = 1; j<=N; j++){
            if(dist[j] == INT_MAX) dist[j] = 0;
            cout << dist[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}