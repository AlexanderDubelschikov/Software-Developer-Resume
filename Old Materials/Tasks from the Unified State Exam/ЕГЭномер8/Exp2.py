from itertools import product
s = list(product('012345678', repeat = 7))
k = 0
for i in s:
    x=''.join(i)
    if x[0]!='0' and x[0]!='3' and x[0]!='7' and x.count('00') + x.count('11') + x.count('22') + x.count('33') + x.count('44') + x.count('55') + x.count('66') + x.count('77') + x.count('88') == 0:
        k=k+1
print(k)