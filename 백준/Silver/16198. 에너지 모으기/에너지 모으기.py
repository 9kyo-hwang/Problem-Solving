input = open(0).readline

N = int(input())
energy_weight = list(map(int,input().split()))

def max_energy(m: int = 0) -> int:
    if len(energy_weight) == 2:
        return m
        
    ans = 0
    for i in range(1,len(energy_weight)-1):
        ball = energy_weight[i - 1] * energy_weight[i + 1]
        v = energy_weight.pop(i)
        ans = max(ans, max_energy(m + ball))
        energy_weight.insert(i, v)
    
    return ans

print(max_energy())