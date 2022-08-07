T = int(input())

for i in range(T):
	N = int(input())
	A = list(map(int, input().split()))
	K = int(input())
	
	KLen = A[K-1]
	
	A.sort()
	
	for j in range(N):
		if A[j] == KLen:
			print(j + 1)
			break