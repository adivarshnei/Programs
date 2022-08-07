T = int(input())

for i in range(T):
	baseExp = input()
	newExp = ''
	placeholder = []
	
	for j in baseExp:
		if 'a' <= j <= 'z':
			newExp += j
		elif j == "(":
			pass
		elif j == ")":
			newExp += placeholder.pop()
		else:
			placeholder.append(j)
	
	print(newExp)