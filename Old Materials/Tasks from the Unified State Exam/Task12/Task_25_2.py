def isPrime(N):
    if N<=1:
        return False
    for d in range(2,round(N**0.5)+1):
        if N%d==0:
            return False
    return True

def alg(st):
    while '01' in st or '02' in st:
        st = st.replace('02','110',1)
        st = st.replace('01','2120',1)
    return st

res = set()

for n in range (87,300):
    for k1 in range(1,n):
        k2= n - 1 - k1
        S = '0' + '1'*k1 + '2'*k2
        R = alg(S)
        summ = sum(map(int,R))
        if isPrime(summ):
            res.add(k1+2*k2)

print(min(res))
