def P(n):
    if n == 1:
        return 1
    else:
        sum = 0
        
        for i in range(1, (n - 1) + 1):
            sum += P(i) * P(n - i)

        return sum

for i in range(1, 11):
    print(f"{i}: {P(i)}")
