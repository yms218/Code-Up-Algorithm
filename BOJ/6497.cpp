#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define MAX 200001
#define Pair pair<pair<int, int>, int>
int N, M;
int p[MAX];
vector<Pair> v;
bool cmp(const Pair& a, const Pair& b){
    if(a.second < b.second) return true;
    return false;
}
int get_p(int x){
    if(x == p[x]) return x;
    return p[x] = get_p(p[x]);
}
void merge(int a, int b){
    a = get_p(a);
    b = get_p(b);
    if(a < b) p[b] = a;
    else p[a] = b;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        v.clear();
        cin >> M >> N;
        int ans = 0;
        if(M == 0 && N == 0) break;
        for(int i = 1; i<=M; i++) p[i] = i; 
        for(int i = 0; i<N; i++){
            int a, b, c; cin >> a >> b >> c;
            v.push_back(make_pair(make_pair(a,b),c));
            ans += c;
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i<v.size(); i++){
            if(get_p(v[i].first.first) != get_p(v[i].first.second)){
                merge(v[i].first.first, v[i].first.second);
                ans -= v[i].second;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}

