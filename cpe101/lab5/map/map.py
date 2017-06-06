import math

def square_all(x):
    y = map(lambda i: i ** 2, x)
    return y

def add_n_all(x, y):
    z = [i + y for i in x]
    return z

def distance_all(x):
    y = []
    for i in x:
        y.append(math.sqrt(i[0] ** 2 + i[1] ** 2))
    return y
