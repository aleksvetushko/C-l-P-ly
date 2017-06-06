import utility 

class Point:
   def __eq__(self, other):
      if utility.epsilon_equal(self.x, other.x, epsilon=0.00001) and utility.epsilon_equal(self.y, other.y, epsilon=0.00001):
         return True
   def __init__(self, x, y):
      self.x = x
      self.y = y

