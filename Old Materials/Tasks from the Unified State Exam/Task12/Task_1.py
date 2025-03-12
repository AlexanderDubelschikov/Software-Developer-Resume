c = '5'*150

while ('5555' in c):
    c = c.replace('5555', '33',1)
    c = c.replace('333', '5',1)

print (c)