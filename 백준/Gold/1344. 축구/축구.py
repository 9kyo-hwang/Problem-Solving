import sys

input_func = sys.stdin.readline

scoring_rate_a = float(input_func())
scoring_rate_b = float(input_func())
scoring_rate_a, scoring_rate_b = scoring_rate_a / 100, scoring_rate_b / 100

total_round = 90 // 5
is_prime = [False] * 2 + [True] * (total_round - 1)
for i in range(2, int((total_round + 1) ** 0.5) + 1):
    if is_prime[i]:
        is_prime[i * i:total_round + 1:i] = [False] * len(range(i * i, total_round + 1, i))

scoring_rate_each_round = [[[0.0] * (total_round + 1) for _ in range(total_round + 1)] for _ in range(total_round + 1)]
scoring_rate_each_round[1][0][0] = (1.0 - scoring_rate_a) * (1.0 - scoring_rate_b)
scoring_rate_each_round[1][1][0] = scoring_rate_a * (1.0 - scoring_rate_b)
scoring_rate_each_round[1][0][1] = (1.0 - scoring_rate_a) * scoring_rate_b
scoring_rate_each_round[1][1][1] = scoring_rate_a * scoring_rate_b

for r in range(2, total_round + 1):
    for a in range(total_round + 1):
        for b in range(total_round + 1):
            scoring_rate_each_round[r][a][b] += scoring_rate_each_round[r - 1][a][b] * (1.0 - scoring_rate_a) * (
                        1.0 - scoring_rate_b)
            if a > 0:
                scoring_rate_each_round[r][a][b] += scoring_rate_each_round[r - 1][a - 1][b] * scoring_rate_a * (
                            1.0 - scoring_rate_b)
            if b > 0:
                scoring_rate_each_round[r][a][b] += scoring_rate_each_round[r - 1][a][b - 1] * (
                            1.0 - scoring_rate_a) * scoring_rate_b
            if a > 0 and b > 0:
                scoring_rate_each_round[r][a][b] += scoring_rate_each_round[r - 1][a - 1][b - 1] * scoring_rate_a * scoring_rate_b

ans = sum(scoring_rate_each_round[total_round][a][b] if is_prime[a] or is_prime[b] else 0.0 for b in range(total_round + 1) for a in range(total_round + 1))
print(ans)