#include <string>
#include <vector>
#include <list>
#include <cstring>

using namespace std;


int solution(int cache_size, vector<string> cities) {
    list<string> cache;
    list<string>::iterator it;
    int answer = 0;
    
    for(const string &city : cities) {
        bool is_find = false;
        for(it = cache.begin(); it != cache.end(); ++it) {
            if(strcasecmp(city.c_str(), (*it).c_str()) == 0) { // cache hit
                it = cache.erase(it);
                cache.emplace_front(city);
                
                is_find = true;
                answer += 1;
                break;
            }
        }

        if(!is_find) { // cache miss
            cache.emplace_front(city);
            if(cache.size() > cache_size) {
                cache.pop_back();
            }
            answer += 5;
        }
    }
    
    return answer;
}