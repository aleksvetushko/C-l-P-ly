import data
import math

def scale_vector(vector, scalar):
   x = vector.x * scalar
   y = vector.y * scalar
   z = vector.z * scalar
   vector2 = data.Vector(x, y, z)
   return vector2

def dot_vector(vector1, vector2):
   x = vector1.x * vector2.x
   y = vector1.y * vector2.y
   z = vector1.z * vector2.z
   vector3 = data.Vector(x, y, z)
   return vector3

def length_vector(vector):
   length = math.sqrt(vector.x ** 2 + vector.y ** 2 + vector.z ** 2)
   return length

def normalize_vector(vector):
   invlength = 1 / math.sqrt(vector.x ** 2 + vector.y ** 2 + vector.z ** 2)
   x = vector.x * invlength
   y = vector.y * invlength
   z = vector.z * invlength
   normalized = data.Vector(x, y, z)
   return normalized

def difference_point(point1, point2):
   x = point1.x - point2.x
   y = point1.y - point2.y
   z = point1.z - point2.z
   vector = data.Vector(x, y, z)
   return vector

def difference_vector(vector1, vector2):
   x = vector1.x - vector2.x
   y = vector1.y - vector2.y
   z = vector1.z - vector2.z
   vector = data.Vector(x, y, z)
   return vector

def translate_point(point, vector):
   x = point.x + vector.x
   y = point.y + vector.y
   z = point.z + vector.z
   point2 = data.Point(x, y, z)
   return point2

def vector_from_to(from_point, to_point):
   x = to_point.x - from_point.x
   y = to_point.y - from_point.y
   z = to_point.z - from_point.z
   vector = data.Vector(x, y, z)
   return vector
