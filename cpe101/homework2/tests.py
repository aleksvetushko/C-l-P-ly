import unittest
import data
import utility
import vector_math
import math

class TestData(unittest.TestCase):
    def test_point_1(self):
        point1 = data.Point(1, 1, 1)
        self.assertTrue(point1.x, 1.00000000001)
        self.assertTrue(point1.y, 1.00000000001)
        self.assertTrue(point1.z, 1.00000000001)
    def test_point_2(self):
        point2 = data.Point(4, 5, 0.00000000001)
        self.assertTrue(point2.x, 4.00000000001)
        self.assertTrue(point2.y, 5.00000000001)
        self.assertTrue(point2.z, 0)
        pass
    def test_vector_1(self):
        vector1 = data.Vector(1.0, 0.00000000001, 0.00000000001)
        self.assertTrue(vector1.x, 1.00000000001)
        self.assertTrue(vector1.y, 0)
        self.assertTrue(vector1.z, 0)
    def test_vector_2(self):
        vector2 = data.Vector(4.0, 3.0, 0.00000000001)
        self.assertTrue(vector2.x, 4.00000000001)
        self.assertTrue(vector2.y, 3.00000000001)
        self.assertTrue(vector2.z, 0)
        pass
    def test_ray_1(self):
        ray1 = data.Ray(data.Point(0.00000000001, 0.00000000001, 0.00000000001), data.Vector(1, 0.00000000001, 0.00000000001))
        self.assertTrue(ray1.pt.x, 0)
        self.assertTrue(ray1.pt.y, 0)
        self.assertTrue(ray1.pt.z, 0)
        self.assertTrue(ray1.dir.x, 1.00000000001)
        self.assertTrue(ray1.dir.y, 0)
        self.assertTrue(ray1.dir.z, 0)
    def test_ray_2(self):
        ray2 = data.Ray(data.Point(1, 2, 3), data.Vector(2.0, 3, 3))
        self.assertTrue(ray2.pt.x, 1.00000000001)
        self.assertTrue(ray2.pt.y, 2.00000000001)
        self.assertTrue(ray2.pt.z, 3.00000000001)
        self.assertTrue(ray2.dir.x, 2.00000000001)
        self.assertTrue(ray2.dir.y, 3.00000000001)
        self.assertTrue(ray2.dir.z, 3.00000000001)
        pass
    def test_sphere_1(self):
        sphere1 = data.Sphere(data.Point(0.00000000001, 0.00000000001, 0.00000000001), 1)
        self.assertTrue(sphere1.center.x, 0)
        self.assertTrue(sphere1.center.y, 0)
        self.assertTrue(sphere1.center.z, 0)
        self.assertTrue(sphere1.radius, 1.00000000001)
    def test_sphere_2(self):
        sphere2 = data.Sphere(data.Point(1, 1, 2), 4.0)
        self.assertTrue(sphere2.center.x, 1.00000000001)
        self.assertTrue(sphere2.center.y, 1.00000000001)
        self.assertTrue(sphere2.center.z, 2.00000000001)
        self.assertTrue(sphere2.radius, 4.00000000001)
        pass

    def test_scale_vector_1(self):
        vectorold = data.Vector(1, 1, 1)
        vectornew = vector_math.scale_vector(vectorold, 2)
        self.assertEqual(vectornew.x, 2)
        self.assertEqual(vectornew.y, 2)
        self.assertEqual(vectornew.z, 2)
    def test_scale_vector_2(self):
        vectorold = data.Vector(4, 1, 3.5)
        vectornew = vector_math.scale_vector(vectorold, 5)
        self.assertEqual(vectornew.x, 20)
        self.assertEqual(vectornew.y, 5)
        self.assertEqual(vectornew.z, 17.5)
        pass
    def test_dot_vector1(self):
        vector1 = data.Vector(1, 1, 1)
        vector2 = data.Vector(1, 1, 1)
        vector3 = vector_math.dot_vector(vector1, vector2)
        self.assertEqual(vector3.x, 1)
        self.assertEqual(vector3.y, 1)
        self.assertEqual(vector3.z, 1)
    def test_dot_vector2(self):
        vector1 = data.Vector(3, 4, 5)
        vector2 = data.Vector(.5, 6, 2)
        vector3 = vector_math.dot_vector(vector1, vector2)
        self.assertEqual(vector3.x, 1.5)
        self.assertEqual(vector3.y, 24)
        self.assertEqual(vector3.z, 10)
        pass
    def test_length_vector1(self):
        vector = data.Vector(1, 0, 0)
        length = vector_math.length_vector(vector)
        self.assertEqual(length, 1)
    def test_length_vector2(self):
        vector = data.Vector(4, 3, 5)
        length = vector_math.length_vector(vector)
        self.assertEqual(length, math.sqrt(50))
        pass
    def test_normalize_vector1(self):
        vector = data.Vector(1, 0, 0)
        normalized = vector_math.normalize_vector(vector)
        self.assertEqual(normalized.x, 1)
        self.assertEqual(normalized.y, 0)
        self.assertEqual(normalized.z, 0)
    def test_normalize_vector2(self):
        vector = data.Vector(3, 4, 3)
        normalized = vector_math.normalize_vector(vector)
        self.assertEqual(normalized.x, 3 / math.sqrt(34))
        self.assertEqual(normalized.y, 4 / math.sqrt(34))
        self.assertEqual(normalized.z, 3 / math.sqrt(34))
        pass
    def test_difference__point1(self):
        point1 = data.Point(4, 4, 4)
        point2 = data.Point(3, 3, 3)
        vector = vector_math.difference_point(point1, point2)
        self.assertEqual(vector.x, 1)
        self.assertEqual(vector.y, 1)
        self.assertEqual(vector.z, 1)
    def test_difference__point2(self):
        point1 = data.Point(5, 1, 3)
        point2 = data.Point(2, 4, 2)
        vector = vector_math.difference_point(point1, point2)
        self.assertEqual(vector.x, 3)
        self.assertEqual(vector.y, -3)
        self.assertEqual(vector.z, 1)
        pass
    def test_difference__vector1(self):
        vector1 = data.Vector(4, 3, 5)
        vector2 = data.Vector(3, 3, 3)
        vector = vector_math.difference_vector(vector1, vector2)
        self.assertEqual(vector.x, 1)
        self.assertEqual(vector.y, 0)
        self.assertEqual(vector.z, 2)
    def test_difference__vector2(self):
        vector1 = data.Vector(1, 5, 2)
        vector2 = data.Vector(2, 1, 5)
        vector = vector_math.difference_vector(vector1, vector2)
        self.assertEqual(vector.x, -1)
        self.assertEqual(vector.y, 4)
        self.assertEqual(vector.z, -3)
        pass
    def test_translate_point1(self):
        point = data.Point(1, 1, 1)
        vector = data.Vector(1, 1, 1)
        point2 = vector_math.translate_point(point, vector)
        self.assertEqual(point2.x, 2)
        self.assertEqual(point2.y, 2)
        self.assertEqual(point2.z, 2)
    def test_translate_point2(self):
        point = data.Point(3, 4, 1)
        vector = data.Vector(6, 0, 2)
        point2 = vector_math.translate_point(point, vector)
        self.assertEqual(point2.x, 9)
        self.assertEqual(point2.y, 4)
        self.assertEqual(point2.z, 3)
        pass
    def test_vector_from_to1(self):
        from_point = data.Point(1, 1, 1)
        to_point = data.Point(2, 2, 2)
        vector = vector_math.vector_from_to(from_point, to_point)
        self.assertEqual(vector.x, 1)
        self.assertEqual(vector.y, 1)
        self.assertEqual(vector.z, 1)
    def test_vector_from_to2(self):
        from_point = data.Point(0, 4, 1)
        to_point = data.Point(9, 2, 6)
        vector = vector_math.vector_from_to(from_point, to_point)
        self.assertEqual(vector.x, 9)
        self.assertEqual(vector.y, -2)
        self.assertEqual(vector.z, 5)
        pass

if __name__ == "__main__":
     unittest.main()
