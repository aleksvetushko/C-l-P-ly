import vehicle
import unittest

class VehicleTests(unittest.TestCase):
   def test_vehicle(self):
    def __init__(self, wheels, fuel, doors, roof):
     self.wheels = 4
     self.fuel = 10
     self.doors = 2
     self.roof = 1
     self.assertEqual(wheels, 4)
     self.assertEqual(fuel, 10)
     self.assertEqual(doors, 2)
     self.assertEqual(roof, 1)
     
      # Add code here.


# Run the unit tests.
if  __name__ == '__main__':
   unittest.main()

