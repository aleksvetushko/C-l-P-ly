import unittest
import conditional

class TestCases(unittest.TestCase):
   def test_case(self):
      self.assertEqual(conditional.max_101(4, 3), 4)
      
   def test_case1(self):
      self.assertEqual(conditional.max_101(4, 6), 6)

   def test_case2(self):
      self.assertEqual(conditional.max_of_three(4.0, 3, 9), 9)

   def test_case3(self):
      self.assertEqual(conditional.max_of_three(4, 6.0, 3), 6.0)

   def test_case4(self):
      self.assertEqual(conditional.rental_late_fee(4), 5)

   def test_case5(self):
      self.assertEqual(conditional.rental_late_fee(24), 19)
      
      # Add code here.
      pass


# Run the unit tests.
if __name__ == '__main__':
   unittest.main()

