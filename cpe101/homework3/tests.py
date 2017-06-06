import unittest
import data
import utility
import vector_math
import math
import collisions

class TestData(unittest.TestCase):
    def test_sphere_intersection_point1(self):
        theRay = data.Ray(data.Point(0, 0, 0), data.Vector(1, 0, 0))
        theSphere = data.Sphere(data.Point(0, 0, 0), 1)
        pointt = collisions.sphere_intersection_point(theRay, theSphere)
        self.assertAlmostEqual(pointt.x, 1.0)
        self.assertAlmostEqual(pointt.y, 0.0)
        self.assertAlmostEqual(pointt.z, 0.0)
    def test_sphere_intersection_point2(self):
        theRay = data.Ray(data.Point(1, 1, 1), data.Vector(1, 0, 0))
        theSphere = data.Sphere(data.Point(1, 1, 1), 1)
        pointt = collisions.sphere_intersection_point(theRay, theSphere)
        self.assertAlmostEqual(pointt.x, 2.0)
        self.assertAlmostEqual(pointt.y, 1.0)
        self.assertAlmostEqual(pointt.z, 1.0)
    def test_find_intersection_points(self):
        sphere_list = [data.Sphere(data.Point(1, 1, 1), 1), data.Sphere(data.Point(3, 3, 3), 1)]
        ray = data.Ray(data.Point(1, 1, 1), data.Vector(1, 0, 0))
        list_of_intersection_pairs = collisions.find_intersection_points(sphere_list, ray)
        self.assertTrue(id(list_of_intersection_pairs), (4300121440, 4300122088))
    def test_find_intersection_points1(self):
        sphere_list = [data.Sphere(data.Point(1, 6, 4), 8), data.Sphere(data.Point(3, 2, 1), 1)]
        ray = data.Ray(data.Point(2, 1, 4), data.Vector(1, 3, 0))
        list_of_intersection_pairs = collisions.find_intersection_points(sphere_list, ray)
        self.assertTrue(id(list_of_intersection_pairs), (4379206576, 4379236616))
    def test_sphere_normal_at_point(self):
        sphere = data.Sphere(data.Point(1, 1, 1), 1)
        point = data.Point(0, 0, 0)
        normalvector = collisions.sphere_normal_at_point(sphere, point)
        self.assertTrue(id(normalvector), 4379149376)
    def test_sphere_normal_at_point1(self):
        sphere = data.Sphere(data.Point(3, 1, 4), 6)
        point = data.Point(0, 1, 0)
        normalvector = collisions.sphere_normal_at_point(sphere, point)
        self.assertTrue(id(normalvector), 4379198528)
if __name__ == "__main__":
     unittest.main()
