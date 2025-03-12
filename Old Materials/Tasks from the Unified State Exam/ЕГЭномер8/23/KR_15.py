def f(x,y):
    if x == 17:
        return 0
    if x == y:
        return 1
    elif x > y:
        return 0
    else:
        return f(x+2,y)+f(x+3,y)+f(x*2,y)
print(f(3,10)*f(10,25))