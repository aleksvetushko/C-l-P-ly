import unittest
import char

class TestChar(unittest.TestCase):
   def test_lower(self):
      x = 'a'
      self.assertAlmostEqual(char.is_lower_101(x), True)
   def test_lower1(self):
      x = 'A'
      self.assertAlmostEqual(char.is_lower_101(x), False)

   def test_rot(self):
      x = 'a'
      self.assertEqual(char.char_rot_13(x), 'n')
   def test_rot1(self):
      x = 'g'
      self.assertEqual(char.char_rot_13(x), 't')      
      
      pass


if __name__ == '__main__':
   unittest.main()

