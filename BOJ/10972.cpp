#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000
int N;
int A[MAX];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i<N; i++) cin >> A[i];
    if(next_permutation(A + 0, A + N)){
        for(int i = 0; i<N; i++) cout << A[i] << " ";
        cout << "\n";
    }
    return 0;
}
