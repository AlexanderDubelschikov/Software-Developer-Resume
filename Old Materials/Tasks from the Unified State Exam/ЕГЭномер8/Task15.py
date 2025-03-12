from itertools import product

letters = 'БАЛКОН'
total_words = 0

for word in product(letters, repeat=5):
    if 'Б' in word:
        total_words += 1

print(total_words)
