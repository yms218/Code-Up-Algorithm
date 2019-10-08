#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define MAX 101
int R, C, M;
int ans;
int A[MAX][MAX];
struct Shark {
    int r,c,s,d,z;
};
Shark shark[MAX * MAX];
// 위,아래,오른쪽,왼쪽
const int dr[] = {0, -1, 1, 0, 0};
const int dc[] = {0, 0, 0, 1, -1};
void kill_shark(int col){
    for(int i = 1; i<=R; i++){
        if(A[i][col]){
           int idx = A[i][col];
           A[i][col] = 0;
           ans += shark[idx].z; 
           return; 
        }
    }
}
void mv_shark() {
    int tmp[MAX][MAX] = {0,};
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=C; j++){
            if(A[i][j]){
                int idx = A[i][j];
                int s = shark[idx].s;
                if(shark[idx].c == 1 && shark[idx].d == 4) shark[idx].d = 3;
                if(shark[idx].c == C && shark[idx].d == 3) shark[idx].d = 4;
                if(shark[idx].r == 1 && shark[idx].d == 1) shark[idx].d = 2;
                if(shark[idx].r == R && shark[idx].d == 2) shark[idx].d = 1;
                int chk = 0;
                if(shark[idx].d < 3) chk = (2*R) - 2;
                else chk = (2*C) - 2;
                int re = s % chk;
                while(re > 0){
                    re--;
                    if(shark[idx].c == 1 && shark[idx].d == 4) shark[idx].d = 3;
                    if(shark[idx].c == C && shark[idx].d == 3) shark[idx].d = 4;
                    if(shark[idx].r == 1 && shark[idx].d == 1) shark[idx].d = 2;
                    if(shark[idx].r == R && shark[idx].d == 2) shark[idx].d = 1;
                    shark[idx].r += dr[shark[idx].d];
                    shark[idx].c += dc[shark[idx].d];
                    
                }
                if(!tmp[shark[idx].r][shark[idx].c]){
                    tmp[shark[idx].r][shark[idx].c] = idx;
                }
                else{
                    int o_idx = tmp[shark[idx].r][shark[idx].c];
                    if(shark[idx].z > shark[o_idx].z){
                        tmp[shark[idx].r][shark[idx].c] = idx;
                    }
                }
            }
        }
    }
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            A[i][j] = tmp[i][j];
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> M;
    for(int i = 1; i<=M; i++){
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        A[shark[i].r][shark[i].c] = i;
    }
    for(int i = 1; i<=C; i++){
        kill_shark(i);
        mv_shark();
    }
    cout << ans << "\n";
    return 0;
}