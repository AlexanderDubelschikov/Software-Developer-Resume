for a in range(-100, 100):
    c = 0
    for x in range(1, 1000):
        for y in range(1, 1000):
            if (((y - 40 < a) and (30 - y < a)) or (x * y > 20)) == False:
                c = 1
                break
        if c == 1:
            break
    if c == 0:
        print(a)
        break
