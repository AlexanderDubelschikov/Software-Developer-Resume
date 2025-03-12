print("x y z w")
for x in range(0, 2):
    for y in range(0, 2):
        for z in range(0, 2):
            for w in range(0, 2):
                if (not((not(x) or y) and not(w)) or not(z and not(y and w)))==False:
                    print(x, y, z, w, '0')
                else:
                    print(x, y, z, w, '1')


