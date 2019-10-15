#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#define max(a,b) ((a > b) ? (a) : (b))
#define min(a,b) ((a < b) ? (a) : (b))
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int hi = 0, lo = 1001;
    for(int i = 0; i<N; i++){
        int val; cin >> val;
        hi = max(hi, val);
        lo = min(lo, val);
    }
    cout << hi - lo << "\n";
    return 0;
}