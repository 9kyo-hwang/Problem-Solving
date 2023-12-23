#include <cstdio>
#include <queue>

int main() {
  int N; scanf(" %d", &N);
  std::deque<int> dq;
  
  while(N--) {
    int cmd; scanf(" %d", &cmd);
    
    switch(cmd) {
      case 1: {
        int n; scanf(" %d", &n); 
        dq.emplace_front(n); 
        break;
      }
      case 2: {
        int n; scanf( "%d", &n); 
        dq.emplace_back(n); 
        break;
      }
      case 3: {
        if(dq.empty()) {
          printf("-1\n");
        } else {
          printf("%d\n", dq.front());
          dq.pop_front();
        }
        break;
      } 
      case 4: {
        if(dq.empty()) {
          printf("-1\n");
        } else {
          printf("%d\n", dq.back());
          dq.pop_back();
        }
        break;
      } 
      case 5: {
        printf("%d\n", dq.size());
        break;
      }
      case 6: {
        printf("%d\n", dq.empty());
        break;
      }
      case 7: {
        if(dq.empty()) {
          printf("-1\n");
        } else {
          printf("%d\n", dq.front());
        }
        break;
      }
      case 8: {
        if(dq.empty()) {
          printf("-1\n");
        } else {
          printf("%d\n", dq.back());
        }
        break;
      }
      default: break;
    }
  }
  
  return 0;
}