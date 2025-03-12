from itertools import permutations

letters = 'РУЛЬКА'

vowels = 'АУ'

k = 0

for perm in permutations(letters, 6):
    code = ''.join(perm)

    if code[0] == 'Ь':
        continue

    valid = True
    for i in range(1, 6):
        if code[i] == 'Ь' and code[i - 1] in vowels:
            valid = False
            break

    if valid:
        k += 1

print(k)

