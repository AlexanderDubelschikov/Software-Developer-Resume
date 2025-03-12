for x in range(1,2031):
    n = 6**260 + 6**160 + 6**60 - x
    k = 0
    while n > 0:
        d = n%6
        if d == 0:
            k += 1
        n = n//6
    if k == 202:
        print(x)
        break
