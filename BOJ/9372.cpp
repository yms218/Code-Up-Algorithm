#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 1001
int p[MAX];
int get_p(int x){
    if(p[x] == x) return x;
    return p[x] = get_p(p[x]);
}
void merge(int a, int b){
    a = get_p(a);
    b = get_p(b);
    if(a < b){
        p[b] = a;
    }
    else{
        p[a] = b;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 0; tc<T; tc++){
        int ans = 0;
        int N, M; cin >> N >> M;
        for(int i = 1; i<=N; i++) p[i] = i;
        for(int i = 0; i<M; i++){
            int a, b; cin >> a >> b;
            if(get_p(a) != get_p(b)){
                ans++;
                merge(a,b);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
