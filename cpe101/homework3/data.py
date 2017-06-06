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
   def __eq__(self, other):
      if utility.epsilon_equal(self.center.x, other.center.x, epsilon=0.00001) and utility.epsilon_equal(self.center.y, other.center.y, epsilon=0.00001) and utility.epsilon_equal(self.center.z, other.center.z, epsilon=0.00001) and utility.epsilon_equal(self.radius, other.radius, epsilon=0.00001):
         return True
   def __init__(self, center, radius):
      self.center = center
      self.radius = radius
