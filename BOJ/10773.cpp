#include <iostream>
using namespace std;

// stack
template <class T>
class _stack {
public:
	struct Node {
		T val;
		Node *next;
		Node(){}
		Node(T val) : val(val), next(0){}
	};
	int _size;
	Node *head;

	_stack() {
		_size = 0;
		head = 0;
	}

	void push(T val){
		Node *temp = new Node(val);
		if (head == 0){
			head = temp;
		}
		else{
			temp->next = head;
			head = temp;
		}
		_size++;
	}

	void pop() {
		Node *temp = head;
		head = head->next;
		delete temp;
		_size--;
	}

	int size() const {
		return _size;
	}

	bool empty() const {
		return _size == 0;
	}

	T top() const {
		return head->val;
	}
};

_stack<int> st;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++){
		int num; cin >> num;
		if (num == 0){
			st.pop();
		}
		else{
			st.push(num);
		}
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << "\n";
	return 0;
}
