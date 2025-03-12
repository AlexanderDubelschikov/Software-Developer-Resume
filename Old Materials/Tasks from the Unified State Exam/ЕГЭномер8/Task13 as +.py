from itertools import product

letters = 'KRT'

k = 0

for combo in product(letters, repeat=5):
    for pos in range(6):
        word = list(combo)
        word.insert(pos, 'O')
        k += 1

print(k)