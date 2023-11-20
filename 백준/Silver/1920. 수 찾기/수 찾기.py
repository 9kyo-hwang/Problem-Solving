input = open(0).readline

N = input()  # 집합에 저장될 수들의 개수
A = set(list(map(int, input().split())))  # 집합에 저장될 N개의 자연수들

M = input()  # 찾고자 하는 수의 개수
B = list(map(int, input().split()))  # M개의 찾고자 하는 수

result = [1 if i in A else 0 for i in B]
print(*result, sep='\n')