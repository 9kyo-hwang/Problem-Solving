import math
input = open(0).readline

MAX = int(1e6) + 1

is_prime = [True] * MAX
primes = []
for i in range(2, int(math.sqrt(MAX))):
    if not is_prime[i]:
        continue
    
    for j in range(i * i, MAX, i):
        is_prime[j] = False
    primes.append(i)


while (n := int(input())) and n != 0:
    flag = False
    for prime in primes:
        if is_prime[n - prime]:
            print("{} = {} + {}".format(n, prime, n - prime))
            flag = True
            break

    if not flag:
        print("Goldbach's conjecture is wrong.")