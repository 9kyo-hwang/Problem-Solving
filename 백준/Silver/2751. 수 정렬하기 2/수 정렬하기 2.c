#include <stdio.h>
#define OFFSET 1000000

int arr[OFFSET * 2 + 1];

int main()
{
    int N; scanf(" %d", &N);
    for(int i = 0; i < N; ++i)
    {
        int n; scanf(" %d", &n);
        arr[n + OFFSET] += 1;
    }
    
    for(int i = 0; i <= OFFSET * 2; ++i)
    {
        for(int j = 0; j < arr[i]; ++j)
        {
            printf("%d\n", i - OFFSET);
        }
    }
    
    return 0;
}