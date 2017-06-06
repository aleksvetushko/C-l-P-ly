import unittest
import fold
import point
import math

class TestCases(unittest.TestCase):
   def test_1(self):
      x = [1, 2, 3]
      self.assertAlmostEqual(fold.sum(x), 6)
   def test_2(self):
      x = [0, -2, 3]
      self.assertAlmostEqual(fold.sum(x), 1)

   def test_3(self):
      x = [1, 2, 3]
      self.assertAlmostEqual(fold.index_of_smallest(x), 0)
   def test_4(self):
      x = [-2, -9, 3]
      self.assertAlmostEqual(fold.index_of_smallest(x), 1)

   def test_5(self):
      x = []
      self.assertAlmostEqual(fold.nearest_origin(x), -1)
   def test_6(self):
      x = [[1, 1], [2, 2], [0, 1]]
      self.assertAlmostEqual(fold.nearest_origin(x), 2)


# Run the unit tests.
if __name__ == '__main__':
   unittest.main()

