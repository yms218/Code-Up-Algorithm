#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ans;
int A[8];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i<N; i++) cin >> A[i];
    sort(A + 0, A + N);
    do {
        int sum = 0;
        for(int i = 0; i<N-1; i++){
            sum += abs(A[i] - A[i+1]);
        }
        ans = max(ans, sum);
    } while(next_permutation(A + 0, A + N));
    cout << ans << "\n";
    return 0;
}