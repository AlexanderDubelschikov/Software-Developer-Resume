def f(start, stop):
    if start > stop:
        return 0
    if start == stop:
        return 1
    return f(start + 2, stop) + f(int(str(start) + '2'), stop)

