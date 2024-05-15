def main():
    import sys
    input = sys.stdin.read
    L, R = input().split()
    
    if len(L) != len(R):
        print(0)
        return
    
    cnt = 0
    for l, r in zip(L, R):
        if l == r and l == '8':
            cnt += 1
        elif l != r:
            break
    print(cnt)
    
if __name__ == "__main__":
    main()