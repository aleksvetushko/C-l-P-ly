import unittest
import logic

class TestCases(unittest.TestCase):
   def test_case(self):
      self.assertEqual(logic.is_even(4), True)

   def test_case1(self):
      self.assertEqual(logic.is_even(3), False)

   def test_case2(self):
      self.assertEqual(logic.in_an_interval(3), True)
      
   def test_case3(self):
      self.assertEqual(logic.in_an_interval(9), False)
      # Add code here.
      pass


# Run the unit tests.
if __name__ == '__main__':
   unittest.main()

