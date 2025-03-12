for i in range(80,100):
  c = '1'*i
  while ('111' in c):
    c = c.replace('111', '2', 1)
    c = c.replace('222', '1', 1)
    if c == '21':
      print (i)
      break