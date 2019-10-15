#include <iostream>
#include <string>
using namespace std;
int N;
char A[10];
void itoc(int num, char *str){
    int temp = num;
    int cnt = 0;
    do {
        cnt++;
        temp /= 10;
    } while(temp != 0);
    str[cnt] = '\0';
    while(num != 0){
        cnt--;
        str[cnt] = (char)(num % 10 + 48);
        num /= 10;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        itoc(i, A);
        for(int j = 0; A[j] != 0; j++){
            if(A[j] == '3' || A[j] == '6' || A[j] == '9') cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
