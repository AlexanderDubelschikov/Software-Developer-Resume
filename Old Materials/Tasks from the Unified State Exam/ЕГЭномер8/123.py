for x in range(0, 2030 + 1):
    c = 6 ** 260 + 6 ** 160 + 6 * 60 - x
    k = 0
    while c >= 6:
        d = c % 6
        if d == 0:
            k += 1
        c = c // 6
    if k == 202:
        print(x)
        break