#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
#define Pair pair<int, int> 
#define MAX 20001
#define INF 987654321
int V, E, K;
int dist[MAX];
vector<Pair> v[MAX];

void dijkstra(int start){
    bool visited[MAX] = {0,};
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;
    dist[start] = 0; // 시작점 거리 = 0
    pq.push(make_pair(0,start));  
    while(!pq.empty()) {
        int cur;
        do{
            cur = pq.top().second;
            pq.pop();
        } while (!pq.empty() && visited[cur]);
        if(visited[cur]) break;
        visited[cur] = true; // 방문
        for(int i = 0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int d = v[cur][i].second;
            // 거리가 갱신될 경우 pq에 새로 넣음
            if(dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    for(int i = 1; i<=V; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E >> K;
    for(int i = 0; i<E; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }
    // initialize dist
    for(int i = 1; i<=V; i++){
        dist[i] = INF;
    }
    dijkstra(K);
    return 0;
}

