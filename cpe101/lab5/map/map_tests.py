import unittest
import map
import point
import math

class TestCases(unittest.TestCase):
   def test_1(self):
      x = [1, 4, 5]
      self.assertAlmostEqual(map.square_all(x), [1, 16, 25])
   def test_2(self):
      x = [-1, 3, 4]
      self.assertAlmostEqual(map.square_all(x), [1, 9, 16])

   def test_3(self):
      x = [1, 4, 5]
      self.assertAlmostEqual(map.add_n_all(x, 3), [4, 7, 8])
   def test_4(self):
      x = [0, -2, 4]
      self.assertAlmostEqual(map.add_n_all(x, 1), [1, -1, 5])

   def test_5(self):
      x = [[0, 0], [1, 1]]
      self.assertAlmostEqual(map.distance_all(x), [0, math.sqrt(2)])
   def test_6(self):
      x = [[2, 2], [4, 3]]
      self.assertAlmostEqual(map.distance_all(x), [math.sqrt(8), 5])
      
      # Add code here.
      pass


# Run the unit tests.
if __name__ == '__main__':
   unittest.main()

