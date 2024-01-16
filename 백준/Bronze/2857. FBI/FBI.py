input = open(0).readline

print(' '.join(i for i in "12345" if "FBI" in input().rstrip()) or "HE GOT AWAY!")