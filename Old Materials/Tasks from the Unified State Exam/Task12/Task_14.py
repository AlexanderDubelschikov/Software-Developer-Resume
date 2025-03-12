for i in range(100,200):
  c = '5'*i
  while ('555' in c) or ('888' in c):
    c = c.replace('555', '8', 1)
    c = c.replace('888', '55', 1)
    if '5' not in c:
      print (i)
      break