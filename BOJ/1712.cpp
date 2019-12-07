#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
// A + (B * X) < C * X
int main(void){
	int A, B, C;
	cin >> A >> B >> C;
    if(B == C){
        cout << -1;
        return 0;
    }
	if((A / (C-B)) + 1 > 0) cout << A / (C-B) + 1;
    else cout << -1 << "\n";
	return 0;	
}