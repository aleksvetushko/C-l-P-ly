import line
import unittest

class LineTests(unittest.TestCase):
   def test_line(self):
    def __init__(self, x1, y1, x2, y2):
     self.x1 = 1
     self.y1 = 1
     self.x2 = 2
     self.y2 = 2
     self.assertEqual(x1, 1)
     self.assertEqual(y1, 1)
     self.assertEqual(x2, 2)
     self.assertEqual(y2, 2)
      # Add code here.
      # 1) Create a Line with x1, y1, x2, y2 values of your choice.
      # 2) Use assertEqual on each field in the new Line to verify
      #    that it holds the expected value.


# Run the unit tests.
if  __name__ == '__main__':
   unittest.main()

