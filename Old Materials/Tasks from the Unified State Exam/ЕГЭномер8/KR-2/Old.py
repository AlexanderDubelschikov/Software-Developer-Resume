from sys import setrecursionlimit
setrecursionlimit(5000)
def F(n):
    if n==1:
        return 1
    if n > 1:
        return 3 * n * F(n-1)
#print(F(2024)/6)
#print(F(2023)/F(2022))
print((F(2024)//6 + F(2023)) / F(2022))