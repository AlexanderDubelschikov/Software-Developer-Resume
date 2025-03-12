from itertools import product

digits = '012345678'

k = 0

for x in product(digits, repeat=7):
    if x[0] == '0':
        continue
    x = ''.join(x)
    if x.count('2') == 1:
        odd_count = sum(1 for d in x if d in '1357')
        if odd_count == 3:
            k += 1

print(k)