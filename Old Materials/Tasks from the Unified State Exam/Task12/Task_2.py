c = '7'*143

while ('777' in c):
    c = c.replace('777', '22',1)
    c = c.replace('222', '7',1)

print (c)