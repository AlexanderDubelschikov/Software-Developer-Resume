def isPalindrome(str):

    for i in range(0, int(len(str)/2)):
        if str[i] != str[len(str)-i-1]:
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
        summ = k1*5 + 2*k2
        S = '0' + '1'*k1 + '2'*k2
        R = alg(S)
        if isPalindrome(R):
            res.add(k1+2*k2)

print(min(res))