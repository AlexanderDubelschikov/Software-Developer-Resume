def WIN(s):
        return s+1>=129 or s*2>=129
def LOSS(s):
    return (not(WIN(s))) and WIN(s+1) and WIN(2*s)

for s in range(1,129):
    if LOSS(s):
        print(s)