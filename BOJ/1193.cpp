#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
1/1 1/2 2/1 3/1 2/2 1/3 1/4 2/3 3/2 4/1 5/1 4/2 3/3 2/4 1/5 1/6...
*/
int main(void){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int N; cin >> N;
        int val = 1, temp = N;
        while(1){
                temp -= val;
                if(temp <= 0){
            break;
        }
        val++;
        }
        if(val % 2 != 0){
       int rest = val + temp;
       int f = val, b = 1;
       for(int i = 1; i<rest; i++){
           f--;
           b++;
       }
       cout << f << "/" << b;
    }
    else{
        int rest = val + temp;
        int f = 1, b = val;
        for(int i = 1; i<rest; i++){
            f++;
            b--;
        }
        cout << f << "/" << b;
    }

        return 0;
}
