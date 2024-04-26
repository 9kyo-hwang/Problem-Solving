#include <stdio.h>
#define MAX 10001

int pre_order[MAX];
int n = 0;

void post_order(int begin, int end) {
    if(begin >= end) {
        if(begin == end) {
            printf("%d\n", pre_order[begin]);
        }
        return;
    }
    
    int sub_begin = begin + 1;
    while(pre_order[begin] > pre_order[sub_begin] && sub_begin <= end) {
        ++sub_begin;
    }
    
    post_order(begin + 1, sub_begin - 1);
    post_order(sub_begin, end);
    printf("%d\n", pre_order[begin]);
}

int main() {
    while(scanf("%d", &pre_order[n]) != EOF) {
        ++n;
    }
 
    post_order(0, n - 1);
    
    return 0;
}