def WIN(s):
    return s + 1 >= 129 or s * 2 >= 129

def LOSS(s):
    return (not (WIN(s))) and WIN(s + 1) and WIN(2 * s)

def WIN_2(s):
    return LOSS(s+1) or LOSS(2*s)

def LOSS1_2(s):
    return WIN(s+1) and WIN_2(2*s) or WIN(2*s) and WIN_2(s+1)


for s in range(1, 129):
    if LOSS1_2(s):
        print(s)