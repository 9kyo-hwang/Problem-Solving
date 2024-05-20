#include <stdio.h>
#include <stdlib.h>
#define MAX 15

int N;
int cols[MAX + 1];

int promising(int level)
{
    for(int i = 1; i < level; ++i)
    {
        if(cols[i] == cols[level] 
        || level - i == abs(cols[level] - cols[i]))
        {
            return 0;
        }
    }
    return 1;
}

int queens(int level)
{
    if(level == N)
    {
        return 1;
    }
    
    int count = 0;
    for(int i = 1; i <= N; ++i)
    {
        cols[level + 1] = i;
        if(promising(level + 1))
        {
            count += queens(level + 1);
        }
    }
    return count;
}

int main()
{
    scanf("%d", &N);
    printf("%d", queens(0));

    return 0;
}