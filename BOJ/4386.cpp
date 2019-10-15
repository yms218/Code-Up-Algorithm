#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 101
int p[MAX];
float ABS(float x, float y){
    if(x >= y) return x - y;
    else return y - x;
}
vector<pair<pair<int, int>, float> > v;
struct POS {float a; float b;};
POS pos[MAX];
float get_dist(int u, int v){
    float x = ABS(pos[u].a, pos[v].a);
    float y = ABS(pos[u].b, pos[v].b);
    float dist = sqrt(x * x + y * y);
    return dist;
}
bool cmp(const pair<pair<int, int>, float>&a, const pair<pair<int, int>, float>&b){
    if(a.second < b.second) return true;
    return false;
}
int get_p(int x){
    if(x == p[x]) return x;
    else return p[x] = get_p(p[x]);
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
    cout << fixed; 
    cout.precision(2);
    int N; cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> pos[i].a >> pos[i].b;
        p[i] = i;
    }
    for(int i = 1; i<N; i++){
        for(int j = i + 1; j<=N; j++){
            v.push_back(make_pair(make_pair(i,j),get_dist(i,j)));
        }
    }
    sort(v.begin(), v.end(), cmp);
    float ans = 0;
    for(int i = 0; i<v.size(); i++){
        if(get_p(v[i].first.first) != get_p(v[i].first.second)){
            merge(v[i].first.first, v[i].first.second);
            ans += v[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}

