#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
// 1, 2~7, 8~19, ..... -1, -6, -12...
int main(void){
	int N; cin >> N;
    N--; int cnt = 1;
    while(N > 0){
        N -= 6 * cnt;
        cnt++;
    }
    cout << cnt << "\n";
	return 0;	
}