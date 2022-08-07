# Program to find average weight

items = [{},{}]

(items[0]['quant'], items[0]['mass']) = map(float, input("Enter the quantity and mass of the first item: ").split(' '))
(items[1]['quant'], items[1]['mass']) = map(float, input("Enter the quantity and mass of the first item: ").split(' '))

print(f"Average mass of the objects = {(items[0]['quant'] * items[0]['mass'] + items[1]['quant'] * items[1]['mass'])/(items[0]['quant'] + items[1]['quant'])}")