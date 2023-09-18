#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cache_size, vector<string> cities)
{
	list<string> cache;
	list<string>::iterator it;
	int times = 0;

	for (string& city : cities)
	{
		for_each(city.begin(), city.end(), [](char& c) {c = tolower(c); });
        
        it = find(cache.begin(), cache.end(), city);
        if(it != cache.end()) // cache hit
        {
            times += 1;
            it = cache.erase(it);
            cache.emplace_front(city);
        }
        else // cache miss
        {
            times += 5;
            cache.emplace_front(city);
		    if (cache.size() > cache_size) 
                cache.pop_back();
        }
	}

	return times;
}