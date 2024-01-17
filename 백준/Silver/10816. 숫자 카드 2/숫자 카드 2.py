from collections import defaultdict

input = open(0).readline

N = int(input())
cards = list(map(int, input().split()))

counter = defaultdict(int)
for card in cards:
    counter[card] += 1

M = int(input())
commands = list(map(int, input().split()))

print(' '.join(str(counter[cmd]) for cmd in commands))