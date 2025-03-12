def f(x,p,k):
    if x>= 88:
        return p%2 == k%2
    if p > k:
        return False
    v = [f(x+1,p+1,k), f(x+4,p+1,k), f(x*3,p+1,k)]
    if p%2 != k%2:
        return any(v)
    else:
        return all(v)

for s in range(1, 81):
    if f(s,0,4) == True and f(s,0,2) == False:
        print(s)
        break