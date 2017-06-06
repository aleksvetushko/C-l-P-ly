import utility

class Point:
   def __eq__(self, other):
      if utility.epsilon_equal(self.x, other.x, epsilon=0.00001) and utility.epsilon_equal(self.y, other.y, epsilon=0.00001) and utility.epsilon_equal(self.z, other.z, epsilon=0.00001):
         return True
   def __init__(self, x, y, z):
      self.x = x
      self.y = y
      self.z = z

class Vector:
   def __eq__(self, other):
      if utility.epsilon_equal(self.x, other.x, epsilon=0.00001) and utility.epsilon_equal(self.y, other.y, epsilon=0.00001) and utility.epsilon_equal(self.z, other.z, epsilon=0.00001):
         return True
   def __init__(self, x, y, z):
      self.x = x
      self.y = y
      self.z = z

class Ray:
   def __eq__(self, other):
      if utility.epsilon_equal(self.pt.x, other.pt.x, epsilon=0.00001) and utility.epsilon_equal(self.pt.y, other.pt.y, epsilon=0.00001) and utility.epsilon_equal(self.pt.z, other.pt.z, epsilon=0.00001) and utility.epsilon_equal(self.dir.x, other.dir.x, epsilon=0.00001) and utility.epsilon_equal(self.dir.y, other.dir.y, epsilon=0.00001) and utility.epsilon_equal(self.dir.z, other.dir.z, epsilon=0.00001):
         return True
   def __init__(self, pt, dir):
      self.pt = pt
      self.dir = dir

class Sphere:
   def __init__(self, center, radius, color, finish):
      self.center = center
      self.radius = radius
      self.color = color
      self.finish = finish

   def __eq__(self, other):
      center = utility.epsilon_equal(self.center, other.center, epsilon=0.00001)
      radius = utility.epsilon_equal(self.radius, other.radius, epsilon=0.00001) 
      color = utility.epsilon_equal(self.color, other.color, epsilon=0.00001)
      finish = utility.epsilon_equal(self.finish, other.finish, epsilon=0.00001)
      return center and radius and color and finish
      
class Color:
   def __init__(self, r, g, b):
      self.r = r
      self.g = g
      self.b = b
   def __eq__(self, other):
      r = utility.epsilon_equal(self.r, other.r, epsilon = 0.00001)
      g = utility.epsilon_equal(self.g, other.g, epsilon = 0.00001)
      b = utility.epsilon_equal(self.b, other.b, epsilon = 0.00001)
      return r and g and b

class Finish:
   def __init__(self, ambient, diffuse, specular, roughness):
      self.ambient = ambient
      self.diffuse = diffuse
      self.specular = specular
      self.roughness = roughness
   def __eq__(self, other):
      ambient = utility.epsilon_equal(self.ambient, other.ambient, epsilon = 0.00001)
      diffuse = utility.epsilon_equal(self.diffuse, other.diffuse, epsilon = 0.00001)
      specular = utility.epsilon_equal(self.specular, other.specular, epsilon = 0.00001)
      roughness = utility.epsilon_equal(self.roughness, other.roughness, epsilon = 0.00001)
      return ambient and diffuse and specular and roughness

class Light:
   def __init__(self, pt, color):
      self.pt = pt
      self.color = color
   def __eq__(self, other):
      point = utility.epsilon_equal(self.pt, other.pt, epsilon = 0.00001)
      color = utility.epsilon_equal(self.color, other.color, epsilon = 0.00001)
