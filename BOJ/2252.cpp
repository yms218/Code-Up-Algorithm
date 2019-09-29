#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;
int N, M;
int inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	for(int i = 1; i<=N; i++){
		if(inDegree[i] == 0) q.push(i);
	}
	for(int i = 1; i<=N; i++){
		if(q.empty()){
			cout << "싸이클 발생\n";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for(int i = 0; i<a[x].size(); i++){
			int y = a[x][i];
			if(--inDegree[y] == 0) q.push(y);
		}
	}
	for(int i = 1; i<=N; i++){
		cout << result[i] << " ";
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int v, w;
	for(int i = 0; i<M; i++){
		cin >> v >> w;
		a[v].push_back(w);
		inDegree[w]++;
	}
	topologySort();
	return 0;
}
