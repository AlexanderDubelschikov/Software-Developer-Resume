from itertools import product

digits = '0123456789ABCDE'

k = 0

for x in product(digits, repeat=5):
    if x[0] == '0':
        continue
    x = ''.join(x)
    if x.count('8') == 1:
        high_digits = sum(1 for d in x if d in 'ABCDE')
        if high_digits >= 2:
            k += 1

print(k)