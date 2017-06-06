import unittest
import funcs
import objects

class TestCases(unittest.TestCase):
   def test_cases(self):
      point1 = objects.Point(4, 4)
      self.assertEqual(point1.x, 4)
      self.assertEqual(point1.y, 4)
      pass

      point2 = objects.Point(1, 1)
      self.assertEqual(point2.x, 1)
      self.assertEqual(point2.y, 1)
      pass

   def test_circle(self):
      circle1 = objects.Circle(point1, 1)
      self.assertEqual(center.x, 4)
      self.assertEqual(center.y, 4)
      self.assertEqual(circle1.radius, 1)

   def test_grow_circle1(self):
      circle1 = objects.Circle(objects.Point(5, 5), 5.0)
      new_circle = funcs.objects.grow_circle(circle1, 2)
      self.assertEqual(objects.circle.center.x, 1)
      
   
      # Add code here.


# Run the unit tests.
if __name__ == '__main__':
   unittest.main()

