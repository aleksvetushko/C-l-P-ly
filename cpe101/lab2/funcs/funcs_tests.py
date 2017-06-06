import unittest
import funcs

class TestCases(unittest.TestCase):
   def test_square(self):
      self.assertEqual(funcs.square(2), 4)

      self.assertEqual(funcs.square(3), 9)
      # Add code here.
      pass


   def test_f(self):
      self.assertEqual(funcs.f(1), 9)

      self.assertEqual(funcs.f(2), 32)
      # Add code here.
      pass

   def test_g(self):
      self.assertEqual(funcs.g(1, 1), 2)

      self.assertEqual(funcs.g(2, 1), 5)
      # Add code here.
      pass

   def test_hypotenuse(self):
      self.assertEqual(funcs.hypotenuse(3, 4), 5)

      self.assertEqual(funcs.hypotenuse(0, 0), 0)
      # Add code here.
      pass

   def test_is_positive(self):
      self.assertEqual(funcs.is_positive(1), True)

      self.assertEqual(funcs.is_positive(4), True)
      # Add code here.
      pass


# Run the unit tests.
if __name__ == '__main__':
   unittest.main()

