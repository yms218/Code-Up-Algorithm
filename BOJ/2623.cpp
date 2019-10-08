#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001
int N, M;
int inDegree[MAX];
int result[MAX];
vector<int> v[MAX];

void topologySort(){
    queue<int> q;
    for(int i = 1; i<=N; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    for(int i = 1; i<=N; i++){
        if(q.empty()){
            cout << "0\n";
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int j = 0; j<v[x].size(); j++){
            int y = v[x][j];
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
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int num; cin >> num;
        int a, b;
        cin >> a;
        for(int j = 0; j<num - 1; j++){
            cin >> b;
            v[a].push_back(b);
            inDegree[b]++;
            a = b;
        }
    }
    topologySort();
    return 0;
}
