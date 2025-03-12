c = '561'*102

while ('1111' in c) or ('56' in c):
    c = c.replace('56', '1',1)
    c = c.replace('1111', '1', 1)

print (c)