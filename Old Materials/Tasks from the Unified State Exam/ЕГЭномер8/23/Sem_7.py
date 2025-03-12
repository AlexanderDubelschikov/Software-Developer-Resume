m = 0
P = [i for i in range(11, 29)]
Q = [i for i in range(5, 56)]
for Amin in range(1, 400):
    for Amax in range(Amin+1, 400):
        check = 1
        A = [i for i in range(Amin, Amax)]
        for x in range(1, 400):
            if (x in A) and ((not((not(x in P)) <= (x in Q))))==True:
                check = 0
                break
        if check == 1:
            m = max(m, Amax - Amin)
print(m-1)