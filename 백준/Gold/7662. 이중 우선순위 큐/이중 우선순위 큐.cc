#include <iostream>
#include <vector>

using namespace std;

class SymmetricMinMaxHeap {
 public:
  SymmetricMinMaxHeap() {}
  ~SymmetricMinMaxHeap() = default;

  void Push(int val) {
    heap.emplace_back(val);
    int node = heap.size() - 1;

    // P1 검증: 자신이 부모의 오른쪽 자식인데 왼쪽 형제보다 작으면 안됨
    if (node % 2 == 1 && heap[node - 1] > val) {
      heap[node] = heap[node - 1];
      node -= 1;
    }

    while (node > 3) { // bubble up
      int grand = node / 4; // 조부모 인덱스
      int left_grand = grand * 2; // 조부모의 왼쪽 자식 인덱스
      int right_grand = grand * 2 + 1; // 조부모의 오른쪽 자식 인덱스

      if (heap[left_grand] > val) {
        // P2 검증: 조부모의 왼쪽 자식들은 모두 자신보다 작거나 같아야 함(조부모의 왼쪽 자식이 자식들 중 가장 작은 값이므로 이 값과 비교)
        heap[node] = heap[left_grand];
        node = left_grand;
      } else if (heap[right_grand] < val) {
        // P3 검증: 조부모의 오른쪽 자식들은 모두 자신보다 크거나 같아야 함(조부모의 오른쪽 자식이 자식들 중 가장 큰 값이므로 이 값과 비교)
        heap[node] = heap[right_grand];
        node = right_grand;
      } else {
        // 검증 완료 -> 종료
        break;
      }
    }
    heap[node] = val;
  }

  void PopMin() {
    if (Empty()) {
      cerr << "Heap Empty\n";
      return;
    }

    int val = heap.back();
    heap.resize(heap.size() - 1);
    if (heap.size() <= 2) {
      return;
    }

    int node = 2;
    while (node * 2 < heap.size()) {
      // P1, P2 조건을 만족하지 않으며 후보 노드의 자식이 존재하는 동안 반복
      int left = node * 2; // 왼쪽 자식 노드
      int left_sibling = (node + 1) * 2; // 오른쪽 형제의 왼쪽 자식 노드

      int min_child = left; // 둘 중 작은 노드 찾기
      if (left_sibling < heap.size() && heap[left_sibling] < heap[min_child]) {
        min_child = left_sibling;
      }

      if (heap[min_child] < val) {
        // P2 검증
        heap[node] = heap[min_child];
        node = min_child;

        // P1 검증
        if (node + 1 < heap.size() && heap[node + 1] < val) {
          heap[node] = heap[node + 1];
          heap[node + 1] = val;
          val = heap[node];
        }
      } else {
        break;
      }
    }
    heap[node] = val;
  }

  void PopMax() {
    if (Empty()) {
      cerr << "Heap Empty\n";
      return;
    }

    int val = heap.back();
    heap.resize(heap.size() - 1);
    if (heap.size() <= 2) {
      return;
    }

    int node = 3;
    while ((node - 1) * 2 + 1 < heap.size()) {
      // P1, P3 조건을 만족하지 않으며 후보 노드의 왼쪽 형제의 오른쪽 자식이 존재하는 동안 반복
      int right = node * 2 + 1;
      int right_sibling = (node - 1) * 2 + 1;

      int max_child = right_sibling;
      if (right < heap.size() && heap[right] > heap[max_child]) {
        max_child = right;
      }

      if (heap[max_child] > val) {
        // P3 검증
        heap[node] = heap[max_child];
        node = max_child;

        // P1 검증
        if (heap[node - 1] > val) {
          heap[node] = heap[node - 1];
          heap[node - 1] = val;
          val = heap[node];
        }
      } else {
        break;
      }
    }
    heap[node] = val;
  }

  void Clear() {
    heap.clear();
    heap.emplace_back(0);
    heap.emplace_back(0);
  }
  size_t Size() { return heap.size() - 2; }
  bool Empty() { return heap.size() == 2; }

  int Min() {
    if (Empty()) {
      cerr << "Heap Empty\n";
      return -1;
    }
    return heap[2];
  }

  int Max() {
    if (Empty()) {
      cerr << "Heap Empty\n";
      return -1;
    }
    return heap.size() == 3 ? heap[2] : heap[3];
  }

 private:
  vector<int> heap;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  SymmetricMinMaxHeap smmh;
  while (T--) {
    smmh.Clear();
    int k;
    cin >> k;

    while (k--) {
      char op;
      int n;
      cin >> op >> n;

      if (op == 'I') {
        smmh.Push(n);
      } else if (!smmh.Empty()) {
        if (n == -1) {
          smmh.PopMin();
        } else {
          smmh.PopMax();
        }
      }
    }

    if (smmh.Empty()) {
      cout << "EMPTY\n";
    } else {
      cout << smmh.Max() << " " << smmh.Min() << "\n";
    }
  }

  return 0;
}