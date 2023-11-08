#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    int N; cin >> N;
	vector<int> stack;
	while (N--) 
	{
		int n; cin >> n;
		switch (n)
		{
		case 1:
			int X; cin >> X;
			stack.emplace_back(X);
			break;
		case 2:
			if (stack.empty()) cout << -1 << "\n";
			else
			{
				cout << stack.back() << "\n";
				stack.pop_back();
			}
			break;
		case 3: 
			cout << stack.size() << "\n";
			break;
		case 4:
			cout << (stack.empty() ? 1 : 0) << "\n";
			break;
		case 5:
			if (stack.empty()) cout << -1 << "\n";
			else cout << stack.back() << "\n";
			break;
		default:
			break;
		}
	}
	return 0;
}