from matplotlib import pyplot as plt

plt.style.use('ggplot')

# Data
# Minutes Passed in game
minutes = [1, 2, 3, 4, 5, 6, 7, 8, 9]

# Points Scored by each player
player1 = [8, 6, 5, 5, 4, 2, 1, 1, 0]
player2 = [0, 1, 2, 2, 2, 4, 4, 4, 4]
player3 = [0, 1, 1, 1, 2, 2, 3, 3, 4]

labels = ['Player1', 'Player2', 'Player3']

plt.title("Stack Plot")

plt.stackplot(minutes, player1, player2, player3, labels=labels)

# plt.legend(loc='lower left')
plt.legend(loc=(0.07, 0.05))
plt.tight_layout()

plt.savefig("stack.png", bbox_inches='tight')
plt.show()
