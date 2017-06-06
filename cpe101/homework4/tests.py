import unittest
import data
import utility
import vector_math
import math
import collisions
import cast

class TestData(unittest.TestCase):
    def test_cast_ray(self):
        ray = data.Ray(data.Point(0, 0, 0), data.Vector(1, 0, 0))
        sphere_list = [data.Sphere(data.Point(1, 1, 1), 1), data.Sphere(data.Point(3, 3, 3), 1)]
        color = data.Color
        boolean = cast.cast_ray(ray, sphere_list, color)
        self.assertEqual(boolean, False)
    def test_cast_ray1(self):
        ray = data.Ray(data.Point(0, 0, 0), data.Vector(1, 0, 0))
        sphere_list = [data.Sphere(data.Point(1, 1, 1), 3), data.Sphere(data.Point(3, 3, 3), 1)]
        boolean = cast.cast_ray(ray, sphere_list)
        self.assertEqual(boolean, True)
        
if __name__ == "__main__":
     unittest.main()
