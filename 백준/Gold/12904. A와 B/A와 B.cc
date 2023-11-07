#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S, T; cin >> S >> T;
	unordered_map<string, bool> visited;
	visited[T] = true;
	
	bool result = false;
	queue<string> q;
	q.emplace(T);
	
	while (!q.empty()) {
		string front = q.front();
		q.pop();

		if (front.length() < S.length())
			continue;

		if (front == S) {
			result = true;
			break;
		}

		if (front.back() == 'A') { // 1st
			front.pop_back(); // pop 'A'
		}
		else { // 2nd
			front.pop_back(); // pop 'B'
			reverse(front.begin(), front.end());
		}

		if (!visited[front]) {
			visited[front] = true;
			q.emplace(front);
		}
	}

	cout << result;

	return 0;
}