#include <iostream>

using namespace std;

class Trie {
 public:
  Trie() : root(new Node) {}
  ~Trie() = default;

  void Insert(const string& str) {
    Node *p = root;
    for (const char &ch : str) {
      int index = ch - 'a';
      if (p->children[index] == nullptr) {
        p->children[index] = new Node;
      }
      p = p->children[index];
    }
    p->isEndOfWord = true;
  }

  bool Find(const string& str) {
    Node *p = root;
    for (const char &ch : str) {
      int index = ch - 'a';
      if (p->children[index] == nullptr) {
        return false;
      }
      p = p->children[index];
    }
    return p->isEndOfWord;
  }

 private:
  static const int ALPHABET_SIZE = 26;
  struct Node {
    bool isEndOfWord;
    Node *children[ALPHABET_SIZE];

    Node() : isEndOfWord(false) {
      for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
      }
    }

    ~Node() = default;
  };

  Node *root;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Trie *trie = new Trie();

  int N, M;
  cin >> N >> M;

  string str;
  while (N--) {
    cin >> str;
    trie->Insert(str);
  }

  int answer = 0;
  while (M--) {
    cin >> str;
    answer += trie->Find(str);
  }
  cout << answer;

  delete trie;

  return 0;
}