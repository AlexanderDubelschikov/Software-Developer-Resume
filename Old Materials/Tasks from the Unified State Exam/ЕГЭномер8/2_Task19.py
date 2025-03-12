print('x y z w F')
for x in range(0,2):
    for y in range(0,2):
        for z in range(0,2):
            for w in range(0, 2):
                    F = x or (z and not(w)) or (y and not(w)) or (y and not(z))
                    if F == 0:
                        print(x,y,z,w,F)