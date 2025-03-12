for x in range(20):
    for y in range(20):
        for z in range(20):
            s='0'+x*'1'+y*'2'+z*'3'+'0'
            while '00' not in s:
                s=s.replace('01','21022',1)
                s=s.replace('02','310',1)
                s=s.replace('03','230112',1)
            if s.count('1')==96 and s.count('2')==36 and s.count('3')==80:
                print(x+y+z+2)
                break