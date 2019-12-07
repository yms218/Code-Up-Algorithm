#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b; cin >> a >> b;
    cout << (b % 10) * a << "\n";
    cout << (b / 10 % 10) * a << "\n";
    cout << (b / 100) * a << "\n";
    cout << a * b << "\n";
    return 0;
}

