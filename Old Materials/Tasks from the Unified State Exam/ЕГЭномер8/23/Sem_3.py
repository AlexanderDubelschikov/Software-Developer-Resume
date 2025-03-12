def f(x,y,z):
    if x == y and z<=2:
        return 1
    if x > y:
        return 0
    if z<=2:
        return f(x + 1, y, z) + f(x * 2, y, z + 1) + f(x * 3, y, z + 1)
    else:
        return f(x+1,y,z)
print(f(1,100,0))