input = open(0).readline

N, S = map(int, input().split())
seq = list(map(int, input().split()))
subtotal = 0

ptr1 = 0
ans = 100001
for ptr2, num in enumerate(seq):
    subtotal += num
    
    while ptr1 <= ptr2 and subtotal >= S:
        ans = min(ans, ptr2 - ptr1 + 1)
        subtotal -= seq[ptr1]
        ptr1 += 1
        
print(0 if ans == 100001 else ans)