def f(x,y,p,k):
    if x+y >= 77:
        return p == k
    if p > k:
        return False
    v = [f(x+1,y,p+1,k), f(x,y+1,p+1,k), f(x*2,y,p+1,k), f(x,y*2,p+1,k)]
    return any(v)

for s in range(1, 70):
    if f(7,s,0,2) == True:
        print(s)
        break