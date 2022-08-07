T = int(input())

for i in range(T):
	(A, B) = map(int, input().split(' '))
	
	evenA = A // 2
	evenB = B // 2
	oddA = (A + 1) // 2
	oddB = (B + 1) // 2
	
	pairs = (evenA * evenB + oddA * oddB)
	
	print(pairs)