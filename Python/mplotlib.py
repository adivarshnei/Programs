from matplotlib import pyplot as plt

ages_x = [25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35]
dev_y = [38496, 42000, 46752, 49320, 53200, 56000, 62316, 64928, 67317, 68748, 73752]

ages_x = [25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35]
py_dev_y = [45372, 48876, 53850, 57827, 63016, 65998, 70003, 70000, 71496, 75370, 83640]

plt.style.use('seaborn-notebook')

plt.bar(ages_x, dev_y, label = 'All Devs')
plt.plot(ages_x, py_dev_y, label = 'Py Devs')
plt.legend()

plt.xlabel('Ages')
plt.ylabel('Median Salary (USD)')
plt.title('Median Salary (USD) by Age')
plt.tight_layout()

plt.legend(['All Devs', 'Py Devs'])

plt.show()

# if __name__ == '__main__':
#     a = int(input("Enter the value of a: "))
#     b = int(input("Enter the value of b: "))
#     print (a + b)
#     print (a - b)
#     print (a * b)