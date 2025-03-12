from itertools import product
s = list(product('СОК',repeat=6))
k=0
for i in s:
    x = ''.join(i)
    if x.count('С')==1:
        k=k+1
print(k)