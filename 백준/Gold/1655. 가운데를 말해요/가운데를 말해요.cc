#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
class MedianPriorityQueue 
{
public:
	void push(T val)
	{
		if (!min_pq.empty() && val > min_pq.top())
		{
			min_pq.emplace(val);
		}
		else
		{
			max_pq.emplace(val);
		}

		this->heapify();
	}

	T top()
	{
		if (max_pq.empty() && min_pq.empty())
		{
			cerr << "Underflow";
			exit(EXIT_FAILURE);
		}

		if (max_pq.size() >= min_pq.size())
		{
			return max_pq.top();
		}
		else
		{
			return min_pq.top();
		}
	}

	void pop()
	{
		if (max_pq.empty() && min_pq.empty())
		{
			cerr << "Underflow";
			exit(EXIT_FAILURE);
		}

		if (max_pq.size() >= min_pq.size())
		{
			max_pq.pop();
		}
		else
		{
			min_pq.pop();
		}
	}

	size_t size()
	{
		return max_pq.size() + min_pq.size();
	}

private:
	priority_queue<T> max_pq;
	priority_queue<T, vector<T>, greater<>> min_pq;

	void heapify()
	{
		if (max_pq.size() - min_pq.size() == 2)
		{
			T top = max_pq.top();
			max_pq.pop();
			min_pq.emplace(top);
		}
		else if(min_pq.size() - max_pq.size() == 2)
		{
			T top = min_pq.top();
			min_pq.pop();
			max_pq.emplace(top);
		}
	}
};

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	MedianPriorityQueue<int> mpq;
	int n;

	while (N--)
	{
		cin >> n;
		mpq.push(n);
		cout << mpq.top() << "\n";
	}
	return 0;
}