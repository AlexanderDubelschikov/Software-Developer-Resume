from itertools import product

consonants = 'КМ'
vowels = 'УА'
letters = 'КУМА'

k = 0

for word in product(letters, repeat=5):
    if word[0] in consonants and word[-1] in vowels:
        k += 1

print(k)
