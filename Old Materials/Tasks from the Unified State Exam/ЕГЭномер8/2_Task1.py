print('a b c F')
for a in range(0,2):
    for b in range(0,2):
        for c in range(0,2):
                F = not a or (b and (not c))
                print(a,b,c,F)