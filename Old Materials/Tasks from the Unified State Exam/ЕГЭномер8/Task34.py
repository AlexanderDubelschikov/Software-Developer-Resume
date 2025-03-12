from itertools import permutations

s = list(permutations('АПОРТ'))

k = 0
for i in s:
    x = ''.join(i)
    OK = True
    for j in range(4):
        if x[j] in 'АО' and x[j+1] in 'АО':
            OK = False
            break
    if OK:
        k += 1

print(k)