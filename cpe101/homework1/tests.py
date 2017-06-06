import unittest
import data

class TestData(unittest.TestCase):
    def test_point_1(self):
        point1 = data.Point(1, 1, 1)
        self.assertAlmostEqual(point1.x, 1)
        self.assertAlmostEqual(point1.y, 1)
        self.assertAlmostEqual(point1.z, 1)
    def test_point_2(self):
        point2 = data.Point(4, 5, 0)
        self.assertAlmostEqual(point2.x, 4)
        self.assertAlmostEqual(point2.y, 5)
        self.assertAlmostEqual(point2.z, 0)
        pass
    def test_vector_1(self):
        vector1 = data.Vector(1.0, 0.0, 0.0)
        self.assertAlmostEqual(vector1.x, 1.0)
        self.assertAlmostEqual(vector1.y, 0.0)
        self.assertAlmostEqual(vector1.z, 0.0)
    def test_vector_2(self):
        vector2 = data.Vector(4.0, 3.0, 0.0)
        self.assertAlmostEqual(vector2.x, 4.0)
        self.assertAlmostEqual(vector2.y, 3.0)
        self.assertAlmostEqual(vector2.z, 0.0)
        pass
    def test_ray_1(self):
        ray1 = data.Ray(data.Point(0, 0, 0), data.Vector(1, 0, 0))
        self.assertAlmostEqual(ray1.pt.x, 0)
        self.assertAlmostEqual(ray1.pt.y, 0)
        self.assertAlmostEqual(ray1.pt.z, 0)
        self.assertAlmostEqual(ray1.dir.x, 1)
        self.assertAlmostEqual(ray1.dir.y, 0)
        self.assertAlmostEqual(ray1.dir.z, 0)
    def test_ray_2(self):
        ray2 = data.Ray(data.Point(1, 2, 3), data.Vector(2.0, 3, 3))
        self.assertAlmostEqual(ray2.pt.x, 1)
        self.assertAlmostEqual(ray2.pt.y, 2)
        self.assertAlmostEqual(ray2.pt.z, 3)
        self.assertAlmostEqual(ray2.dir.x, 2.0)
        self.assertAlmostEqual(ray2.dir.y, 3)
        self.assertAlmostEqual(ray2.dir.z, 3)
        pass
    def test_sphere_1(self):
        sphere1 = data.Sphere(data.Point(0, 0, 0), 1)
        self.assertAlmostEqual(sphere1.center.x, 0)
        self.assertAlmostEqual(sphere1.center.y, 0)
        self.assertAlmostEqual(sphere1.center.z, 0)
        self.assertAlmostEqual(sphere1.radius, 1)
    def test_sphere_2(self):
        sphere2 = data.Sphere(data.Point(1, 1, 2), 4.0)
        self.assertAlmostEqual(sphere2.center.x, 1)
        self.assertAlmostEqual(sphere2.center.y, 1)
        self.assertAlmostEqual(sphere2.center.z, 2)
        self.assertAlmostEqual(sphere2.radius, 4.0)
        pass

if __name__ == "__main__":
     unittest.main()
