input = open(0).readline

mid = int(1e7)
cvt = lambda x : x + mid

num_cards = [0] * (2 * mid + 1)

N = int(input())
cards = list(map(int, input().split()))
for card in cards:
    num_cards[cvt(card)] += 1

M = int(input())
commands = list(map(int, input().split()))
for cmd in commands:
    print(num_cards[cvt(cmd)], end=' ')