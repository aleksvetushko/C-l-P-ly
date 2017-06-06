import monster
import unittest

class MonsterTests(unittest.TestCase):
   def test_monster(self):
    def __init__(self, eyes, arms, height, tails):
     self.eyes = 2
     self.arms = 2
     self.height = 50
     self.tails = 1
     self.assertEqual(eyes, 2)
     self.assertEqual(arms, 2)
     self.assertEqual(height, 50)
     self.assertEqual(tails, 1)
      # Add code here.


# Run the unit tests.
if  __name__ == '__main__':
   unittest.main()

