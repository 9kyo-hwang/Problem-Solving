#include <string>
#include <vector>

using namespace std;

class Trie {
    public:
    Trie() : size(0), end(false) { 
        next.assign(26, nullptr); 
    }
    
    ~Trie() {
        for(int i = 0; i < 26; i++) {
            if(next[i] != nullptr)
                delete next[i];
        }
    }
    
    void Insert(const char *str) {
        size++;
        
        if(*str == '\0') {
            end = true;
            return;
        }
        
        int idx = *str - 'a';
        if(next[idx] == nullptr)
            next[idx] = new Trie();
        next[idx]->Insert(str + 1);
    }
    
    int Find(const char *str, int cnt = 0) {
        if(size == 1 || *str == '\0') {
            return cnt;
        }
        
        return next[*str - 'a']->Find(str + 1, cnt + 1);
    }
    
    private:
    int size;
    bool end;
    vector<Trie*> next;
};

Trie trie;

int solution(vector<string> words) {
    for(const string &word : words) {
        trie.Insert(word.c_str());
    }
    
    int answer = 0;
    for(const string &word : words) {
        answer += trie.Find(word.c_str());
    }
    return answer;
}