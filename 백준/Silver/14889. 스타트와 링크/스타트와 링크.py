import sys
import itertools

input = sys.stdin.read

def main():
    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1
    
    Table = []
    for _ in range(N):
        Table.append([int(data[idx + i]) for i in range(N)])
        idx += N

    Answer = 40001
    half_N = N // 2
    total_comb = 1 << N
    
    memo = {}
    
    def team_score(team):
        if team in memo:
            return memo[team]
        score = 0
        for i in range(half_N):
            for j in range(i + 1, half_N):
                score += Table[team[i]][team[j]] + Table[team[j]][team[i]]
        memo[team] = score
        return score
    
    for comb in range(1, total_comb):
        if bin(comb).count('1') != half_N:
            continue
        
        Start = [i for i in range(N) if comb & (1 << i)]
        Link = [i for i in range(N) if not comb & (1 << i)]
        
        StartScore = team_score(tuple(Start))
        LinkScore = team_score(tuple(Link))
        
        Answer = min(Answer, abs(StartScore - LinkScore))
    
    print(Answer)

if __name__ == "__main__":
    main()
