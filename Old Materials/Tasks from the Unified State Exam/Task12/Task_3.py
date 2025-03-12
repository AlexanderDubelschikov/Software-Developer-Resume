c = '1'*120

while ('111' in c):
    c = c.replace('111', '2',1)
    c = c.replace('222', '3', 1)
    c = c.replace('333', '1', 1)

print (c)