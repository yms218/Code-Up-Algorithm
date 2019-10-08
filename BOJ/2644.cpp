#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 101
int N, M, n1, n2;
vector<int> v[MAX];
void BFS(){
    queue<int> q;
    bool visited[MAX] = {false,};
    q.push(n1);
    visited[n1] = true;
    int st = 0;
    while(!q.empty()){
        int q_size = q.size();
        while(q_size--){
            int now = q.front();
            if(now == n2) {
                cout << st << "\n";
                return;
            }
            q.pop();
            for(int i = 0; i<v[now].size(); i++){
                int next = v[now][i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        st++;
    }
    cout << "-1\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> n1 >> n2;
    cin >> M;
    for(int i = 0; i<M; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    BFS();
    return 0;
}