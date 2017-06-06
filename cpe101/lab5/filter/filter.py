def are_positive(x):
    y = filter(lambda i: i > 0, x)
    return y

def are_greater_than(x, y):
    y = filter(lambda i: i > y, x)
    return y

def are_in_first_quadrant(x):
    y = filter(lambda i: i[0] > 0 and i[1] > 0, x)
    return y
