for i in range(201,300):
  c = '5'*i
  while ('555' in c) or ('888' in c):
    c = c.replace('555', '8', 1)
    c = c.replace('888', '55', 1)
  if c.count('5')==c.count('8'):
    print (i)
    break