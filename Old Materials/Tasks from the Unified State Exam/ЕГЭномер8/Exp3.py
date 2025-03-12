from itertools import permutations
s = list(permutations('0123456789', 6))
k = 0
for i in s:
    x=''.join(i)
    if x[0]!='0' and (x[-1]=='0' or x[-1]=='5'):
        OK=True
        for j in range (0,5):
            if int(x[j])%2==int(x[j+1])%2:
                OK=False
                break
        if OK==True:
            k=k+1
print(k)





