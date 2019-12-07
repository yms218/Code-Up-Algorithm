#include <iostream>
using namespace std;
// dp
int A[1001];
int dp[1001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i<=N; i++) cin >> A[i];
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] + A[j]);
        }
    }
    cout << dp[N] << "\n";
    return 0;
}