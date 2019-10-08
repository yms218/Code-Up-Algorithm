#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
// 1005번 : ACM Craft
// 알고리즘 : 위상정렬
// 시간복잡도 : N + M
#define MAX 32001
int N, M;
int inDegree[MAX];
int result[MAX];
int ans[MAX];
int cost[MAX];
vector<int> v[MAX];

int topologySort(int end){
    queue<int> q;
    for(int i = 1; i<=N; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    for(int i = 1; i<=N; i++){
        if(q.empty()){
            return 0;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int j = 0; j<v[x].size(); j++){
            int y = v[x][j];
            ans[y] = max(ans[y], ans[x] + cost[y]);
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }
    return ans[end];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for(int tc = 0; tc<t; tc++){
        cin >> N >> M;
        for(int i = 1; i<=N; i++){
            v[i].clear();
            inDegree[i] = 0;
            cin >> cost[i];
            ans[i] = cost[i];
        }
        for(int i = 1; i<=M; i++){
            int a, b; cin >> a >> b;
            v[a].push_back(b);
            inDegree[b]++;
        }
        int num; cin >> num;
        cout << topologySort(num) << "\n";
    }
    
    return 0;
}


