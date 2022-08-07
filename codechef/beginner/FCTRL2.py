def factorial (num):
	fact = 1
	
	while num > 0:
		fact *= num
		num-=1;
		
	return fact

t = int(input())

for i in range(t):
	n = int(input())
	
	print(factorial(n))