from itertools import product
s = list(product('АЗИМУТ', repeat = 6))
k = 0
for i in s:
    x=''.join(i)
    if x.count('З') + x.count('М') + x.count('Т') >2:
        k=k+1
print(k)