#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S, T; cin >> S >> T;
	
	bool result = false;

	while (S.length() <= T.length()) {
		if (S == T) {
			result = true;
			break;
		}
		
		if (T.back() == 'A') {
			T.pop_back();
		} 
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}

	cout << result;

	return 0;
}