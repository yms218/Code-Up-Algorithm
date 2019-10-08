#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
// 1766번 : 문제집
// 알고리즘 : 위상정렬
// 시간복잡도 : N + M
#define MAX 32001
int N, M;
int inDegree[MAX];
int result[MAX];
vector<int> v[MAX];

void topologySort(){
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 1; i<=N; i++){
        if(inDegree[i] == 0) pq.push(i);
    }
    for(int i = 1; i<=N; i++){
        if(pq.empty()){
            cout << "0\n";
            return;
        }
        int x = pq.top();
        pq.pop();
        result[i] = x;
        for(int j = 0; j<v[x].size(); j++){
            int y = v[x][j];
            if(--inDegree[y] == 0){
                pq.push(y);
            }
        }
    }
    
    for(int i = 1; i<=N; i++){
        cout << result[i] << " ";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }
    topologySort();
    return 0;
}

