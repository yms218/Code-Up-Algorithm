#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
int A[11];
bool cmp(const int& a, const int& b){
    if(a > b) return true;
    return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> A[i];
    }
    sort(A + 0, A + N, cmp);
    int ans = 0;
    for(int i = 0; i<N; i++){
        if(K < A[i]) continue;
        if(K == 0) break;
        int temp = K / A[i];
        K = K - temp * A[i];
        ans += temp;
    }
    cout << ans << "\n";
    return 0;
}


