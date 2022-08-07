T = int(input())

for i in range(T):	
	A = int(input())
	digSum = 0
	
	while A > 0:
		digSum += A % 10
		A = A // 10
	
	print(digSum)