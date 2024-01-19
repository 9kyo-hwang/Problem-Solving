import math
input = open(0).readline

MAX = int(1e6) + 1

is_prime = [True] * MAX
for i in range(2, int(math.sqrt(MAX))):
    if is_prime[i]:
        for j in range(i * i, MAX, i):
            is_prime[j] = False


while (n := int(input())) and n != 0:
    flag = False
    for i in range(3, n // 2 + 1, 2):
        if is_prime[i] and is_prime[n - i]:
            print("{} = {} + {}".format(n, i, n - i))
            flag = True
            break

    if not flag:
        print("Goldbach's conjecture is wrong.")