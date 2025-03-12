from itertools import permutations

hex_digits = '0123456789ABCDEF'
s = list(permutations(hex_digits, 5))

k = 0
for i in s:
    x = ''.join(i)
    if x[0] == '0':
        continue
    OK = True
    for j in range(4):
        current_even = int(x[j], 16) % 2 == 0
        next_even = int(x[j + 1], 16) % 2 == 0
        if current_even == next_even:
            OK = False
            break
    if OK:  
        k += 1

print(k)