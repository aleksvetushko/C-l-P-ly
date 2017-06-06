import math
import objects

def square(x):
    return x ** 2

def f(x):
    return 7 * x ** 2 + 2 * x

def g(x, y):
    return x ** 2 + y ** 2

def hypotenuse(x, y):
    return math.sqrt(x ** 2 + y ** 2)

def is_positive(x):
    return x > 0

def grow_circle(circle1, rate):
    circlecenter = circle1.center
    circleradius = circle1.radius
    new_radius = circleR * rate
    circle2 = objects.Circle(circlecenter, new_radius)
    return circle2

def distance(point1, point2):
    dist = math.sqrt( (point1.x - point2.x) ** 2 + (point1.y - point2.y) ** 2)
    return dist

def circles_overlap(circle1, circle2):
    centerdist = math.sqrt( (circle1.center.x  - circle2.center.x) ** 2 + (circle1.center.y - circle2.center.y) ** 2)
    radiisum = circle1.radius + circle2.radius
    if centerdist < radiisum:
        return True
    else:
        return False

