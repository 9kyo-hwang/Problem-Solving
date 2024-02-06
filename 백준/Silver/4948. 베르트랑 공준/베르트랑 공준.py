input = open(0).readline
MAX = 123456 * 2

is_prime = [False] * 2 + [True] * (MAX - 1)
for i in range(2, int(MAX**0.5) + 1):
    if not is_prime[i]:
        continue
    
    for j in range(i * i, MAX + 1, i):
        is_prime[j] = False


while (n := int(input())) and n != 0:
    print(sum(is_prime[i] for i in range(n + 1, n * 2 + 1)))