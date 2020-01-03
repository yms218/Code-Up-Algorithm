#include <iostream>
#include <stack>
using namespace std;
char ch[101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin.getline(ch, 101)) {
		if (ch[0] == '.') break;
		bool flag = false;
		stack<char> st;
		for (int i = 0; ch[i] != 0; i++) {
			if (ch[i] == '(' || ch[i] == '[') st.push(ch[i]);
			else if(ch[i] == ')' || ch[i] == ']') {
				if (st.empty()) flag = true;
				else {
					if (ch[i] == ')' && st.top() == '(') st.pop();
					else if (ch[i] == ']' && st.top() == '[') st.pop();
					else flag = true;
				}
			}
		}
		if (!st.empty()) flag = true;
		if (flag == true) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}
