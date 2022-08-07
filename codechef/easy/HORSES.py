T = int(input())

for i in range(T):
	N = int(input())
	S = list(map(int, input().split(' ')))
	S.sort()
	
	diff = S[1]-S[0]
	
	for j in range(N-1):
		diff = min(diff, S[j + 1] - S[j])
	
	print(diff)