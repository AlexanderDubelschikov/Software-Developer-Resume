from sys import setrecursionlimit
setrecursionlimit(10**6)
def F(n):
    if n==1:
        return 1
    if n>1:
        return 3*n*F(n-1)
print(((F(2024)/6+F(2023))/F(2022)))