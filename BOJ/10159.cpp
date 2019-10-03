#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
// 1 - 2 - 3 - 4
//        6   5
// 백준 10159번 : 저울 
// 알고리즘 : 플로이드 와샬
// if(a > b && b > c) => a > c
#define MAX 101
#define Pair pair<int, int>
#define INF 500000
int dist[MAX][MAX];
int N, M;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int a, b; 
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for(int k = 1; k<=N; k++){
        for(int i =1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(dist[i][k] && dist[k][j]) dist[i][j] = 1;
            }
        }
    }
    for(int i = 1; i<=N; i++){
        int cnt = 0;
        for(int j = 1; j<=N; j++){
            if(!dist[i][j] && !dist[j][i]) cnt ++;
        }
        cout << cnt - 1 << "\n";
    }
    return 0;
}
