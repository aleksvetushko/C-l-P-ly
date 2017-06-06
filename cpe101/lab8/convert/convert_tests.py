import unittest
import convert

class TestConvert(unittest.TestCase):
   def test_convert1(self):
      x = convert.float_default('1.5', 5)
      self.assertEqual(x, 1.5)
   def test_convert2(self):
      x = convert.float_default('abc', 5)
      self.assertEqual(x, 5)
      pass


if __name__ == '__main__':
   unittest.main()

