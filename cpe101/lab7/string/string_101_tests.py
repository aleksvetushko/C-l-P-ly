import unittest
import string_101

class TestString(unittest.TestCase):
   def test_lower1(self):
      s = 'lad'
      self.assertEqual(string_101.str_rot_13(s), 'ynq')
   def test_lower2(self):
      s = 'and'
      self.assertEqual(string_101.str_rot_13(s), 'naq')
   
   def test_lower3(self):
      s = 'and'
      self.assertEqual(string_101.str_translate_101(s, 'a', 'b'), 'bnd')
      pass
   def test_lower4(self):
      s = 'cccaaa'
      self.assertEqual(string_101.str_translate_101(s, 'a', 'c'), 'cccccc')
      pass


if __name__ == '__main__':
   unittest.main()

