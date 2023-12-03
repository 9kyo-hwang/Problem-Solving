#include <cstdio>
#include <cstdlib>

#define MAX 15

int queens(int);
bool promising(int);

int cols[MAX + 1]; 
int N;

int main() {
    scanf("%d", &N);
    printf("%d", queens(0));

    return 0;
}

int queens(int level) {
    if(!promising(level))
        return 0;
    else if(level == N) {
        return 1;
    }
    else {
        int count = 0;
        for(int i = 1; i <= N; i++) {
            cols[level + 1] = i;
            count += queens(level + 1);
        }
        return count;
    }
}

bool promising(int level) {
    for(int i = 1; i < level; i++) {
        if(cols[i] == cols[level])
            return false;
        else if(level - i == abs(cols[level] - cols[i]))
            return false;
    }
    return true;
}