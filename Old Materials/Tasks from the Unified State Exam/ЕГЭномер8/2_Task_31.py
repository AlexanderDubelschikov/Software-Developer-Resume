print('x y z w F')
for x in range(0,2):
    for y in range(0,2):
        for z in range(0,2):
            for w in range(0, 2):
                    F = (w and y) or ((x<=w)==(y<=z))
                    if F == 0:
                        print(x,y,z,w,F)