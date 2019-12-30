#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;
int N, M;
vector<string> v;

#define MAX_TABLE 50007
#define MAX_NODE 500007

struct Node {
	char name[21];
	Node* next;
} nd[MAX_NODE];
int ndidx;
Node* newnode() { return &nd[++ndidx]; }

struct Bucket {
	int count;
	Node* head;
} HashTB[MAX_TABLE];

void str_cpy(char* a, char* b) {
	for (int i = 0; b[i] != 0; i++) {
		a[i] = b[i];
	}
}

int str_cmp(char* a, char* b) {
	int i = 0;
	while (a[i]) {
		if (a[i] != b[i]) break;
		i++;
	}
	return (a[i] - b[i]);
}

unsigned long get_key(char* str) {
	int c;
	unsigned long hash = 5381;
	while (c = *str++) {
		hash = (((hash << 5) + hash) + c);
	}
	return hash % MAX_TABLE;
}

void add(char* str) {
	unsigned long h = get_key(str);
	Node* node = newnode();
	str_cpy(node->name, str);
	if(HashTB[h].count == 0){}
	else {
		node->next = HashTB[h].head;
	}
	HashTB[h].head = node;
	HashTB[h].count++;
	return;
}

bool chk(char* str) {
	unsigned long h = get_key(str);
	Node* node = HashTB[h].head;
	while (node) {
		if (str_cmp(node->name, str) == 0) {
			return true;
		}
		node = node->next;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		char name[21] = { 0, }; cin >> name;
		add(name);
	}
	for (int i = 0; i < M; i++) {
		char name[21] = { 0, }; cin >> name;
		if (chk(name)) {
			v.push_back(name);
		}
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}