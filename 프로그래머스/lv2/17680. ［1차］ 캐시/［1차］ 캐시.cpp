#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cache_size, vector<string> cities)
{
	deque<string> cache;
	deque<string>::iterator it;
	int times = 0;

	for (string& city : cities)
	{
		for_each(city.begin(), city.end(), [](char& c) {c = tolower(c); });
		bool find = false;
		for (it = cache.begin(); it != cache.end(); ++it)
		{
			if ((*it) == city)
			{
				times += 1;
				find = true;

				it = cache.erase(it);
				cache.emplace_front(city);
				break;
			}
		}

		if (find) continue;

		cache.emplace_front(city);
		if (cache.size() > cache_size) cache.pop_back();
		times += 5;
	}

	return times;
}