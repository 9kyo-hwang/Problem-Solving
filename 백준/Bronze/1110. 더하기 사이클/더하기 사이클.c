#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);
    int M = N;
    int Cnt = 0;
    
    do
    {
        M = (M % 10 * 10) + (M % 10 + M / 10) % 10;
        Cnt += 1;
    } while(N ^ M);

    printf("%d", Cnt);
    
    return 0;
}