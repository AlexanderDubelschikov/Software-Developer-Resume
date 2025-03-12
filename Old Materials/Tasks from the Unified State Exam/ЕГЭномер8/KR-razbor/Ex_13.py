from itertools import product

alphabet = '01234567'
cnt = 0
for i in product(alphabet, repeat=5):
    if i[0] in '246':
        if i[-1] not in '26':
            if i.count('7') <= 2:
                cnt += 1

print(cnt)