#include <iostream>
#include <string>
using namespace std;
char ch[501];
int str_len(char* str){
    int i;
    for(i=0; str[i] != 0; i++){}
    return i;
}
int main(void){
    while(1){
        cin.getline(ch, 501);
        int len = str_len(ch);
        if(len == 3){
            if(ch[0] == 'E' && ch[1] == 'N' && ch[2] == 'D'){
                return 0;
            }
        }
        for(int i = len - 1; i>=0; i--){
            cout << ch[i];
        }
        cout << "\n";
    }
    
    return 0;
}