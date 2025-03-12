from itertools import permutations

letters = 'ГЕРАКЛИТ'

vowels = 'ЕАИ'
consonants = 'ГРКЛТ'

k = 0

for combo in permutations(letters, 6):
    code = ''.join(combo)

    vowel_count = sum(1 for c in code if c in vowels)
    consonant_count = 6 - vowel_count
    if consonant_count <= vowel_count:
        continue

    valid = True
    for i in range(5):
        if code[i] in vowels and code[i + 1] in vowels:
            valid = False
            break

    if valid:
        k += 1

print(k)
