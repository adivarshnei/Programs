def wordPrint(num):
    numWord = { 'tens': [],
               'hundreds': [],
               'thousands': [] }
    
    if num % 100 < 20:
        if num == 1:
            numWord['tens'].append('one')
        elif num == 2:
            numWord['tens'].append('two')
        elif num == 3:
            numWord['tens'].append('three')
        elif num == 4:
            numWord['tens'].append('four')
        elif num == 5:
            numWord['tens'].append('five')
        elif num == 6:
            numWord['tens'].append('six')
        elif num == 7:
            numWord['tens'].append('seven')
        elif num == 8:
            numWord['tens'].append('eight')
        elif num == 9:
            numWord['tens'].append('nine')
        elif num == 10:
            numWord['tens'].append('ten')
        elif num == 11:
            numWord['tens'].append('eleven')
        elif num == 12:
            numWord['tens'].append('twelve')
        elif num == 13:
            numWord['tens'].append('thirteen')
        elif num == 14:
            numWord['tens'].append('fourteen')
        elif num == 15:
            numWord['tens'].append('fifteen')
        elif num == 16:
            numWord['tens'].append('sixteen')
        elif num == 17:
            numWord['tens'].append('seventeen')
        elif num == 18:
            numWord['tens'].append('eighteen')
        elif num == 19:
            numWord['tens'].append('nineteen')
    else:
        if (num % 100) - (num % 10) == 20:
            numWord['tens'].append('twenty')
        elif (num % 100) - (num % 10) == 30:
            numWord['tens'].append('thirty')
        elif (num % 100) - (num % 10) == 40:
            numWord['tens'].append('forty')
        elif (num % 100) - (num % 10) == 50:
            numWord['tens'].append('fifty')
        elif (num % 100) - (num % 10) == 60:
            numWord['tens'].append('sixty')
        elif (num % 100) - (num % 10) == 70:
            numWord['tens'].append('seventy')
        elif (num % 100) - (num % 10) == 80:
            numWord['tens'].append('eighty')
        elif (num % 100) - (num % 10) == 90:
            numWord['tens'].append('ninety')
            
        if num % 10 == 1:
            numWord['tens'].append('one')
        elif num % 10 == 2:
            numWord['tens'].append('two')
        elif num % 10 == 3:
            numWord['tens'].append('three')
        elif num % 10 == 4:
            numWord['tens'].append('four')
        elif num % 10 == 5:
            numWord['tens'].append('five')
        elif num % 10 == 6:
            numWord['tens'].append('six')
        elif num % 10 == 7:
            numWord['tens'].append('seven')
        elif num % 10 == 8:
            numWord['tens'].append('eight')
        elif num % 10 == 9:
            numWord['tens'].append('nine')
            
    if (num % 1000) - (num % 100) == 100:
        numWord['hundreds'].append('one')
    elif (num % 1000) - (num % 100) == 200:
        numWord['hundreds'].append('two')
    elif (num % 1000) - (num % 100) == 300:
        numWord['hundreds'].append('three')
    elif (num % 1000) - (num % 100) == 400:
        numWord['hundreds'].append('four')
    elif (num % 1000) - (num % 100) == 500:
        numWord['hundreds'].append('five')
    elif (num % 1000) - (num % 100) == 600:
        numWord['hundreds'].append('six')
    elif (num % 1000) - (num % 100) == 700:
        numWord['hundreds'].append('seven')
    elif (num % 1000) - (num % 100) == 800:
        numWord['hundreds'].append('eight')
    elif (num % 1000) - (num % 100) == 900:
        numWord['hundreds'].append('nine')
    
    if (num % 1000) - (num % 100) != 0:
        numWord['hundreds'].append('hundred')
    
    if num - (num % 1000) == 1000:
        numWord['thousands'].append('one')
    elif num - (num % 1000) == 2000:
        numWord['thousands'].append('two')
    elif num - (num % 1000) == 3000:
        numWord['thousands'].append('three')
    elif num - (num % 1000) == 4000:
        numWord['thousands'].append('four')
    elif num - (num % 1000) == 5000:
        numWord['thousands'].append('five')
    elif num - (num % 1000) == 6000:
        numWord['thousands'].append('six')
    elif num - (num % 1000) == 7000:
        numWord['thousands'].append('seven')
    elif num - (num % 1000) == 8000:
        numWord['thousands'].append('eight')
    elif num - (num % 1000) == 9000:
        numWord['thousands'].append('nine')
        
    if num - (num % 1000) != 0:
        numWord['thousands'].append('thousand')
        
    print(numWord['thousands'][0] + ' ' + numWord['thousands'][1] + ' ' + numWord['hundreds'][0] + ' ' + numWord['hundreds'][1] + ' ' + numWord['tens'][0] + ' ' + numWord['tens'][1])

num = int(input("Enter the number: "))

wordPrint(num)