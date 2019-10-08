#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
// 9470번 : Strahler 순서
// 알고리즘 : 위상정렬
// 시간복잡도 : N + P
#define MAX 1001
int K, N, P;
int inDegree[MAX];
int Strahler[MAX];
int cnt[MAX];

vector<int> v[MAX];

void topologySort(int tc){
    queue<int> q;
    for(int i = 1; i<=N; i++){
        if(inDegree[i] == 0) {
            q.push(i);
            Strahler[i] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        if(q.empty()){
            return;
        }
        int x = q.front();
        q.pop();
        if(cnt[x] > 0) Strahler[x]++;
        ans = max(ans, Strahler[x]);
        for(int j = 0; j<v[x].size(); j++){
            int y = v[x][j];
            if(Strahler[y]<Strahler[x]) {
                Strahler[y] = Strahler[x];
                cnt[y] = 0;
            }
            else if(Strahler[y] == Strahler[x]) cnt[y]++;
            if(--inDegree[y] == 0){            
                q.push(y);
            }
        }
    }
    
    cout << tc << " " << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for(int tc = 0; tc<t; tc++){
        cin >> K >> N >> P;
        for(int i = 1; i<=N; i++){
            inDegree[i] = 0;
            cnt[i] = 0;
            Strahler[i] = 0;
            v[i].clear();
        }
        for(int i = 0; i<P; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            inDegree[b]++;
        }
        topologySort(tc + 1);
    }
    
    return 0;
}


