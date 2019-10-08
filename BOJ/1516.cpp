#include <iostream>
#include <queue>
using namespace std;
#define MAX 501
// 위상정렬 개념잡기 좋은 문제
int inDegree[MAX];
int cost[MAX];
int result[MAX];
int N;
vector<int> A[MAX];

void topologySort() {
    
    queue<int> q;
    for(int i = 1; i<=N; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    for(int i = 1; i<=N; i++){
        if(q.empty()){
            cout << "cycle!!";
            return;
        }
        int x = q.front();
        q.pop();
        for(int i = 0; i<A[x].size(); i++){
            int y = A[x][i];
            result[y] = max(result[y], result[x] + cost[y]);
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }
    for(int i = 1; i<=N; i++){
        cout << result[i] << "\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> cost[i];
        result[i] = cost[i];
        while(1){
            int a; cin >> a;
            if(a == -1) break;
            A[a].push_back(i);
            inDegree[i]++;
        }
    }
    topologySort();
    return 0;
}