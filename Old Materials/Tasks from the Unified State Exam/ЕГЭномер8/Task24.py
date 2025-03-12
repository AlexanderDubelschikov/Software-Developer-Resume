from itertools import product

letters = 'КЛЕЙ'
total_words = 0

for word in product(letters, repeat=6):
    if word.count('Й') <= 1 and word[0] != 'Й' and word[-1] != 'Й':
        valid = True
        for i in range(5):
            if (word[i] == 'Й' and word[i + 1] == 'Е') or (word[i] == 'Е' and word[i + 1] == 'Й'):
                valid = False
                break
        if valid:
            total_words += 1

print(total_words)
