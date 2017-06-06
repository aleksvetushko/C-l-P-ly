import math

def sum(x):
    ret = 0
    for i in x:
        ret += i
    return ret

def index_of_smallest(x):
    return x.index(min(x))

def nearest_origin(x):
    if x == []:
        return -1
    else:
        y = []
        for i in x:
            y.append(math.sqrt(i[0] ** 2 + i[1] ** 2))
        return y.index(min(y))
