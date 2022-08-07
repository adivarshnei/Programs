(A,B) = map(int, input().split(' '))

result = A - B

if result % 10 < 9:
	result += 1
else:
	result -= 1
	
print(result)