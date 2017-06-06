import unittest
import poly

class TestPoly(unittest.TestCase):

   def assertListAlmostEqual(self, l1, l2):
      self.assertEqual(len(l1), len(l2))
      for el1, el2 in zip(l1, l2):
         self.assertAlmostEqual(el1, el2)

   def test_poly(self):
      poly1 = [3.2, 3.2, 3.2]
      poly2 = [3.2, 3.2, 3.2]
      poly3 = poly.poly_add2(poly1, poly2)
      self.assertListAlmostEqual(poly3, [6.4, 6.4, 6.4])

   def test_poly1(self):
      poly1 = [-1, 3.0, 4]
      poly2 = [6, 4, 3.0]
      poly3 = poly.poly_add2(poly1, poly2)
      self.assertListAlmostEqual(poly3, [5, 7.0, 7.0])

   def test_poly2(self):
      poly1 = [1, 1, 1]
      poly2 = [1, 1, 1]
      poly3 = poly.poly_mult2(poly1, poly2)
      self.assertListAlmostEqual(poly3, [1, 2, 3, 2, 1])

   def test_poly3(self):
      poly1 = [2, 3, 4]
      poly2 = [1, 2, 1]
      poly3 = poly.poly_mult2(poly1, poly2)
      self.assertListAlmostEqual(poly3, [2, 7, 12, 11, 4])
      pass
      
   # Add tests here

if __name__ == '__main__':
   unittest.main()
