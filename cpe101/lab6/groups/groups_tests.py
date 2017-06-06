import unittest
import groups

class TestGroups(unittest.TestCase):

   def assertListAlmostEqual(self, l1, l2):
      self.assertEqual(len(l1), len(l2))
      for el1, el2 in zip(l1, l2):
         self.assertAlmostEqual(el1, el2)

   def test1(self):
      x = [1, 2, 3, 4, 5, 6, 7, 8]
      self.assertListAlmostEqual(groups.groups_of_three(x), [[1, 2, 3], [4, 5, 6], [7, 8]])
   def test2(self):
      x = [1, 2, 3, 4, -4, 8]
      self.assertListAlmostEqual(groups.groups_of_three(x), [[1, 2, 3], [4, -4, 8]])


   # Add tests here

if __name__ == '__main__':
   unittest.main()
