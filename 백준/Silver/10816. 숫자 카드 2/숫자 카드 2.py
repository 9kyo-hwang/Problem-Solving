input = open(0).readline

N = int(input())
cards = list(map(int, input().split()))

counter = {}
for card in cards:
    if card not in counter:
        counter[card] = 1
    else:
        counter[card] += 1

M = int(input())
commands = list(map(int, input().split()))

print(' '.join(str(counter[cmd]) if cmd in counter else '0' for cmd in commands))