T = int(input())

for i in range(T):
	N = int(input())
	
	Zn = 0
	
	while N != 0:
		N //= 5
		Zn += N
		
	print(Zn)