def add(num1, num2):
    return num1 + num2

def poly_add2(x, y):
    z = []
    z.append(x[0] + y[0])
    z.append(x[1] + y[1])
    z.append(x[2] + y[2])
    return z
    
def poly_mult2(x, y):
    z = []
    z.append(x[0]*y[0])
    z.append(x[0]*y[1] + x[1]*y[0])
    z.append(x[0]*y[2] + x[1]*y[1] + x[2]*y[0])
    z.append(x[1]*y[2] + x[2]*y[1])
    z.append(x[2]*y[2])
    return z
