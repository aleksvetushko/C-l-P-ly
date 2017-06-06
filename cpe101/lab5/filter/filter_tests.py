import unittest
import filter
import point

class TestCases(unittest.TestCase):
   def test_1(self):
      x = [-1, 2, -4]
      self.assertAlmostEqual(filter.are_positive(x), [2])   
   def test_2(self):
      x = [-3, -2, 4]
      self.assertAlmostEqual(filter.are_positive(x), [4])

   def test_3(self):
      x = [-3, -2, 4]
      self.assertAlmostEqual(filter.are_greater_than(x, 3), [4])
   def test_4(self):
      x = [-3, -2, 4]
      self.assertAlmostEqual(filter.are_greater_than(x, -3), [-2, 4])

   def test_5(self):
      x = [[1, 1], [-2, 4], [4, 4]]
      self.assertAlmostEqual(filter.are_in_first_quadrant(x), [[1, 1], [4, 4]])
   def test_6(self):
      x = [[-1, 1], [2, 4], [-4, 4]]
      self.assertAlmostEqual(filter.are_in_first_quadrant(x), [[2, 4]])
      
      # Add code here.
      pass


# Run the unit tests.
if __name__ == '__main__':
   unittest.main()
