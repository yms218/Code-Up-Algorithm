#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
// 백준 1613번 : 역사 
// 알고리즘 : 플로이드 와샬
// 시간복잡도 : O(n^3)
#define MAX 401
int N, K;
int dist[MAX][MAX];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i<K; i++){
        int a, b; cin >> a >> b;
        dist[a][b] = 1; // a->b사건이 일어남
    }
    // a->b, b->c 사건이 일어났으면 a->c임
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(dist[i][k] && dist[k][j]) dist[i][j] = 1;
            }
        }
    }

    int s; cin >> s;
    for(int i = 0; i<s; i++){
        int a, b; cin >> a >> b;
        if(dist[a][b]) cout << "-1\n";
        else if(dist[b][a]) cout << "1\n";
        else if(!dist[a][b] && !dist[b][a]) cout << "0\n";
    }
    return 0;
}
