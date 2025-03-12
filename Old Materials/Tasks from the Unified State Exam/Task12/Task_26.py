for x in range(60):
    for y in range(60):
        for z in range(60):
            s = '0' + x*'1' + y*'2' + z*'3' +'0'
            while '00' not in s:
                s = s.replace('01','320',1)
                s = s.replace('02','2013', 1)
                s = s.replace('03','1210', 1)
            if s.count('1')==36 and s.count('2')==30:
                print(x+y+z+2)