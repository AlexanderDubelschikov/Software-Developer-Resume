k1 = 0
for x in range(1, 2031):
    c = 6 ** 2030 + 6 ** 100 - x
    k = 0
    while c >= 6:
        d = c % 6
        if d == 0:
            k += 1
        c = c // 6
    k1 = max(k,k1)
print (k1)